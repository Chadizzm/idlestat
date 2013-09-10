CFLAGS?=-g -Wall
CC?=gcc

OBJS = idlestat.o topology.o trace.o utils.o

default: idlestat

idlestat: $(OBJS)
	$(CC) ${CFLAGS} $(OBJS) -o $@

clean:
	rm -f $(OBJS) idlestat
