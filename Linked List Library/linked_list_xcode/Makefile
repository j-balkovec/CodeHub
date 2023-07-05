CC = g++
CFLAGS = -std=c++17 -Wall

all: prog

prog: single_l.o main.o test_file.o
	$(CC) $(CFLAGS) $^ -o $@

single_l.o: single_l.cpp single_l.h
	$(CC) $(CFLAGS) -c $<

main.o: main.cpp single_l.h test_file.h test.h
	$(CC) $(CFLAGS) -c $<

test_file.o: test_file.cpp test_file.h single_l.h test.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o prog
