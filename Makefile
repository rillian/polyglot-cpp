PROGS := main

all: main

main_SRCS := main.cpp Circle.cpp Rectangle.cpp
main_OBJS := $(main_SRCS:%.cpp=%.o)

TESTS := test

test_SRCS := test.cpp
test_OBJS := $(test_SRCS:%.cpp=%.o)
LDFLAGS ?= -L /usr/local/lib -lboost_unit_test_framework-mt

CPPFLAGS = -I /usr/local/include
CXXFLAGS = -g -Wall --std=c++14

main: $(main_OBJS)
	c++ -o $@ $^

check: all $(TESTS)
	@for prog in $(TESTS); do ./$${prog}; done
	@for prog in $(PROGS); do ./$${prog}; done

clean:
	$(RM) $(test_OBJS)
	$(RM) $(TESTS)
	$(RM) $(main_OBJS)
	$(RM) $(PROGS)
