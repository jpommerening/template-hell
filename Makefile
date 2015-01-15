
CXX ?= g++
CFLAGS ?= -Wall -Wextra -O3

OBJS = units/unit.o units/si_units.o units/si_derived_units.o units/imperial_units.o units/planck_units.o
DEPS = $(OBJS:%.o=%.d)

.PHONY: all

all: $(OBJS)

clean:
	rm -f $(OBJS) $(DEPS)

-include $(DEPS)

%.d: %.cc Makefile
	$(CXX) $(CFLAGS) -MM -o $@ $<

%.o: %.cc %.d
	$(CXX) $(CFLAGS) -c -o $@ $<
