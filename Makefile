all: $(basename $(wildcard *.cpp *.cc))

%: %.cpp
	c++ -g -Wall --std=c++14 -o $@ $^
