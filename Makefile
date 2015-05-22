PROGS := main

all: main

main_SRCS := main.cpp Circle.cpp Rectangle.cpp
main_OBJS := $(main_SRCS:%.cpp=%.o)

CXXFLAGS = -g -Wall --std=c++14

main: $(main_OBJS)
	c++ -o $@ $^

check: all
	@for prog in $(PROGS); do ./$${prog}; done

clean:
	$(RM) $(main_OBJS)
	$(RM) $(PROGS)
