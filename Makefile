PROGS = driver

OBJS = sum_array_c.o sum_array_s.o find_max_c.o find_max_s.o fib_iter_c.o fib_iter_s.o fib_rec_c.o fib_rec_s.o find_str_c.o find_str_s.o tower_c.o tower_s.o
CFLAGS = -g

all : ${PROGS}

%.o : %.c
	gcc -c ${CFLAGS} -o $@ $<

%.o : %.s
	as -o $@ $<

driver : driver.c ${OBJS}
	gcc -o driver driver.c ${OBJS}

clean :
	rm -rf ${PROGS} ${OBJS}
