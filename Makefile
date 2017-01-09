# my first Makefile

CC = gcc
#CC = arm-none-linux-gnueabi-gcc
CFLAGS = -Wall -g -std=gnu99 -DDEBUG3 -DMY_ALGO
STDLIBS= -lrt 

all: sort.c
	rm -rf *.o 
	rm -rf ./sort
	clear
	$(CC) $(CFLAGS) sort.c  $(STDLIBS)  -o sort
	
clean:
	rm -rf *.o 
	rm -rf ./sort

