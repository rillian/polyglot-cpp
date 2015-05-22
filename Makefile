PROGS := main

CXXFLAGS = -g -Wall --std=c++14

main_SRCS := main.cpp Circle.cpp Rectangle.cpp

TESTS := test array even exception fib hello

test_SRCS := test.cpp test_circle.cpp Circle.cpp
test_CPPFLAGS := -I /usr/local/include
test_LDFLAGS := -L /usr/local/lib -lboost_unit_test_framework

array_SRCS := array.cpp
even_SRCS := even.cpp
exception_SRCS := exception.cpp
fib_SRCS := fib.cpp
hello_SRCS := hello.cpp


## below this point is generic code

all: $(PROGS)

check: all $(TESTS)
	@for prog in $(TESTS); do ./$${prog}; done

clean:
	$(RM) $(ALL_OBJS)
	$(RM) $(TESTS)
	$(RM) $(PROGS)

# generate rules for each target

define prog_template
$(1)_OBJS := $$($(1)_SRCS:%.cpp=%.o)
$$($(1)_OBJS) : CPPFLAGS += $$($(1)_CPPFLAGS)
ALL_OBJS += $$($1_OBJS)
$(1): $$($(1)_OBJS)
	$(CXX) -o $$@ $$^ $$(LDFLAGS) $$($(1)_LDFLAGS)
endef

$(foreach prog,$(PROGS),$(eval $(call prog_template,$(prog))))
$(foreach prog,$(TESTS),$(eval $(call prog_template,$(prog))))
