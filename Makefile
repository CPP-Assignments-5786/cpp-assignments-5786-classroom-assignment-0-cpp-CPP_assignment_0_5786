CXX=clang++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion
TIDY_FLAGS=-checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=*
TIDY_EXCLUDE=test.cpp main.cpp

SOURCES=Student.cpp
OBJECTS=Student.o

all: demo
	./demo

grade: test tidy

demo: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestRunner.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) TestRunner.o $(OBJECTS) -o test
	./test

TestRunner.o: test.cpp Student.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

Student.o: Student.cpp Student.hpp

main.o: main.cpp Student.hpp

tidy:
	clang-tidy $(filter-out $(TIDY_EXCLUDE), $(SOURCES)) $(TIDY_FLAGS) -- $(CXXFLAGS)

clean:
	rm -f *.o demo test

.PHONY: all test clean tidy grade