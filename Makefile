
CXX = g++
CFLAGS = -Wall -Wextra -O3

OBJS = units/unit.o units/si_units.o units/si_derived_units.o units/imperial_units.o
DEPS = $(OBJS:%.o=%.d)

.PHONY: default all

default: all

all: $(OBJS)

%.d: %.cc
	$(CXX) $(CFLAGS) -MM -o $@ $<

%.o: %.cc %.d
	$(CXX) $(CFLAGS) -c -o $@ $<

-include $(DEPS)
