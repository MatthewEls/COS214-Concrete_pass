# Compiler and flags
CXX = g++
CXXFLAGS = $(shell wx-config --cxxflags)
LDLIBS = $(shell wx-config --libs)

# Source files and object files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXECUTABLE = test

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) -g -o $@ $^ $(LDLIBS)

%.o: %.cpp
	$(CXX) -c -g $(CXXFLAGS) -o $@ $<

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(OBJS) $(EXECUTABLE)

debug: $(EXECUTABLE)
	gdb $(EXECUTABLE)

tar:
	tar -cvf archive.tar makefile *.cpp *.h

.PHONY: all run clean debug tar