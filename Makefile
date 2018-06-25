# compiler variables and flags
CC := g++
# CC := mpic++
CFLAGS := -std=c++11 -g -Wall
# DFLAGS := -DMPI
LIB := -L lib -lyaml-cpp -lboost_system -lboost_filesystem
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

# boost install variables
BOOST_FILES := lib/libboost_filesystem.a lib/libboost_system.a

# sources for tests
TEST_SRC := test/test_main.o $(filter-out test/test_main.cpp, $(shell find test -name *.cpp))
TEST_SRC += $(filter-out src/main.cpp, $(SOURCES))

$(TARGET): $(YAML_FILES) $(BOOST_FILES) $(OBJECTS)
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
	    make install && \
	    rm -r include/gmock include/gtest

$(BOOST_FILES):
	tools/install-boost.sh

clean:
	@echo " Cleaning...";
	$(RM) -r $(BUILDDIR)/* bin/*

hardclean: clean
	$(RM) -r include/yaml-cpp include/boost lib test/*.o

format: tools/clang-format-all.sh tools/clang-format
	@echo "Formatting .cpp and .hpp files..."
	$<

tools/clang-format:
	tools/install-clang-format.sh

.PHONY: yaml-cpp clean hardclean format

# Test stuff
test/test_main.o: test/test_main.cpp test/catch.hpp
	$(CC) $(CFLAGS) $< -c -o $@

bin/test: $(YAML_FILES) $(BOOST_FILES) $(TEST_SRC)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(TEST_SRC) $(INC) -o $@ $(LIB)

test: bin/test
	bin/test

.PHONY: test
