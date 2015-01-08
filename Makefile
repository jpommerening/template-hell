
CXX = g++
CFLAGS = -Wall -Wextra -O23

OBJS = units/unit.o units/si_units.o units/imperial_units.o
DEPS = $(OBJS:%.o=%.d)

.PHONY: default all

default: all

all: $(OBJS)

-include $(DEPS)
