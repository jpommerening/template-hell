
CXX = g++
CFLAGS = -Wall -Wextra -O23

OBJS = units/unit.o units/si_units.o
DEPS = $(OBJS:%.o=%.d)

-include $(DEPS)
