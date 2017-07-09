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

$(TARGET): $(OBJECTS)
	@echo " Linking..."
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@echo " $(CC) $(CFLAGS) $(DFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(DFLAGS) $(INC) -c -o $@ $<

byref: spike/byref.cpp
	$(CC) $(CFLAGS) $(INC) -o spike/byref spike/byref.cpp $(LIB)

byref2: spike/byref2.cpp
	$(CC) $(CFLAGS) $(INC) -o spike/byref2 spike/byref2.cpp $(LIB)

byref3: spike/byref3.cpp
	$(CC) $(CFLAGS) $(INC) -o spike/byref3 spike/byref3.cpp $(LIB)

clean:
	@echo " Cleaning...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

.PHONY: clean
