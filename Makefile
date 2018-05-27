# compiler variables and flags
CC := g++
# CC := mpic++
CFLAGS := -std=c++11 -g -Wall
# DFLAGS := -DMPI
LIB := -L lib -lyaml-cpp
INC := -I include
TARGET := bin/pnc-ft

# build sources and objects lists
SRCDIR := src
BUILDDIR := build
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# yaml-cpp install variables
PWD := $(shell pwd)
YAML_CPP := /tmp/yaml-cpp
YAML_CPP_INSTALL_PREFIX := $(PWD)
CMAKE_CC := $(shell which gcc)
CMAKE_CXX := $(shell which g++)
YAML_FILES := $(YAML_CPP_INSTALL_PREFIX)/lib/libyaml-cpp.a \
              $(YAML_CPP_INSTALL_PREFIX)/include/yaml-cpp/yaml.h

# sources for tests
TEST_SRC := test/test_main.o test/test_init.cpp
TEST_SRC += $(filter-out src/main.cpp, $(SOURCES))

$(TARGET): $(YAML_FILES) $(OBJECTS)
	@echo " Linking..."
	@mkdir -p $(dir $@)
	$(CC) $(OBJECTS) -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DFLAGS) $(INC) -c -o $@ $<

# Install yaml-cpp files in include/ and lib/ under YAML_CPP_INSTALL_PREFIX,
# which is this project's root directory by default
$(YAML_FILES):
	rm -rf $(YAML_CPP)
	git clone https://github.com/jbeder/yaml-cpp $(YAML_CPP) && \
	    mkdir $(YAML_CPP)/build && \
	    cd $(YAML_CPP)/build && \
	    CC=$(CMAKE_CC) CXX=$(CMAKE_CXX) \
	        cmake -DCMAKE_INSTALL_PREFIX=$(YAML_CPP_INSTALL_PREFIX) .. && \
	    make && \
	    make install

clean:
	@echo " Cleaning...";
	$(RM) -r $(BUILDDIR) bin test/*.o

hardclean: clean
	$(RM) -r include lib

.PHONY: yaml-cpp clean hardclean

# Test stuff
test/test_main.o: test/test_main.cpp test/catch.hpp
	$(CC) $(CFLAGS) $< -c -o $@

bin/test: $(TEST_SRC) $(YAML_FILES)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ $(INC) -o $@ $(LIB)

test: bin/test
	bin/test

.PHONY: test
