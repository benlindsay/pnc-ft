CC := g++ # This is the main compiler
# CC := mpic++
SRCDIR := src
BUILDDIR := build
TARGET := bin/pnc-ft

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -std=c++11 -g -Wall
# DFLAGS := -DMPI
LIB := -lyaml-cpp -L lib
INC := -I include

TESTER_SRC := test/tester.cpp $(filter-out src/main.cpp, $(SOURCES))

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@echo " $(CC) $(CFLAGS) $(DFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(DFLAGS) $(INC) -c -o $@ $<

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) $(TESTER_SRC) $(INC) $(LIB) -o bin/tester

.PHONY: clean
