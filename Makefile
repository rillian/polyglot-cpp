PROGS := $(basename $(wildcard *.cpp *.cc))

all: $(PROGS)

%: %.cpp
	c++ -g -Wall --std=c++14 -o $@ $^

check: all
	@for prog in $(PROGS); do ./$${prog}; done

clean:
	$(RM) $(PROGS)
