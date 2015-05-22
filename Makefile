PROGS := main test

all: $(PROGS)

main_SRCS := main.cpp Circle.cpp Rectangle.cpp
main_OBJS := $(main_SRCS:%.cpp=%.o)

TESTS := test

test_SRCS := test.cpp test_circle.cpp Circle.cpp
test_OBJS := $(test_SRCS:%.cpp=%.o)
test_CPPFLAGS := -I /usr/local/include
test_LDFLAGS := -L /usr/local/lib -lboost_unit_test_framework

CXXFLAGS = -g -Wall --std=c++14

check: all $(TESTS)
	@for prog in $(TESTS); do ./$${prog}; done

clean:
	-$(RM) $(ALL_OBJS)
	$(RM) $(PROGS)

  
## generate rules for each target

define prog_template
$$($(1)_OBJS) := $$($(1)_SRCS:%.cpp=%.o)
$$($(1)_OBJS) : CPPFLAGS += $$($(1)_CPPFLAGS)
ALL_OBJS += $$($1_OBJS)
$(1): $$($(1)_OBJS)
	$(CXX) -o $$@ $$^ $$(LDFLAGS) $$($(1)_LDFLAGS)
endef

$(foreach prog,$(PROGS),$(eval $(call prog_template,$(prog))))
