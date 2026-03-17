CXX=clang++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion
TIDY_FLAGS=-checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-* --warnings-as-errors=*
TIDY_EXCLUDE=test.cpp main.cpp

all: demo
	./demo

grade: test tidy

demo: main.o Student.o
	$(CXX) $(CXXFLAGS) $^ -o demo
 
test: TestRunner.o Student.o
	$(CXX) $(CXXFLAGS) $^ -o test
	./test
 
TestRunner.o: test.cpp Student.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o
 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@
 
Student.o: Student.cpp Student.hpp
 
main.o: main.cpp Student.hpp
 
tidy:
	clang-tidy Student.cpp $(TIDY_FLAGS) -- $(CXXFLAGS)
 
clean:
	rm -f *.o demo test
 
.PHONY: all test clean tidy grade
