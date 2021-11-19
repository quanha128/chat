main: main.o bigint.o
	gcc -g $^ -o $@

%.o: %.c
	gcc -Wall -c -g $< -o $@

bigint.o: bigint.c bigint.h

clean:
	rm -f *.o