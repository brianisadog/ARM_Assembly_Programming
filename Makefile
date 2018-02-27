PROGS = driver

OBJS = sum_array_c.o sum_array_s.o
CFLAGS = -g

all : ${PROGS}

sum_array_c.o : sum_array_c.c
	gcc -c -o sum_array_c.o sum_array_c.c

sum_array_s.o : sum_array_s.s
	as -o sum_array_s.o sum_array_s.s

driver : driver.c ${OBJS}
	gcc -o driver driver.c ${OBJS}

clean :
	rm -rf ${PROGS} ${OBJS}
