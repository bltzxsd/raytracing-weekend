CXX := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -g
LDFLAGS :=

SRCDIR := src
BUILDDIR := build
DEBUGDIR := debug
TARGET := output.exe

SOURCES := $(wildcard $(SRCDIR)/*.cc)
OBJECTS := $(patsubst $(SRCDIR)/%.cc,$(BUILDDIR)/%.o,$(SOURCES))

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(DEBUGDIR)/$(TARGET) $(OBJECTS) $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cc
	@if not exist "$(BUILDDIR)" mkdir "$(BUILDDIR)"
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean run

clean:
	rm -rf $(BUILDDIR) out.ppm

run: $(TARGET)
	./$(DEBUGDIR)/$(TARGET)
	code out.ppm

build: $(TARGET)
	@if not exist "$(DEBUGDIR)" mkdir "$(DEBUGDIR)"
