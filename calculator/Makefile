PROGRAMS = calc

CC = tcc
CFLAGS = -g

all: $(PROGRAMS)

calc: main.o getop.o stack.o getch.o
	$(CC) -o calculator.exe main.o getop.o stack.o getch.o

main.o: main.c calc.h

getop.o: getop.c calc.h

stack.o: stack.c calc.h

getch.o: getch.c calc.h

getop.o: getop.c calc.h

clean:
	rm -f $(PROGRAMS) *.o

.PHONY: all clean
