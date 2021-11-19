.PHONY: all clean

all: post show

post: post.o diary.o
	gcc -Wall -g $^ -o $@

show: show.o diary.o
	gcc -Wall -g $^ -o $@

%.o: %.c
	gcc -Wall -g -c $< -o $@

clean:
	rm -f post show *.o diary.bin

post.o: post.c diary.h
show.o: show.c diary.h
diary.o: diary.c diary.h
