CXX = g++
CXXFLAGS = -std=c++11 -Wall
SOURCES = main.cpp Employee.cpp MaitreD.cpp Waiter.cpp HeadChef.cpp Chef.cpp DrinksChef.cpp SousChef.cpp GrillChef.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = milkshake_app

.PHONY: all run clean

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)