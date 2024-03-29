progname = minied
CC = gcc
CFLAGS = -Wall -W -Og -static -fuse-ld=lld -z norelro -g
CPPFLAGS = 
LDFLAGS = -z norelro -static -Wl,--image-base=0x8000000
objs = main.o main_loop.o carg_parser.o

.PHONY : all

all: $(progname)

$(progname) : $(objs)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(objs)

main.o : main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(objs) 	  : Makefile miniminied.h
carg_parser.o : carg_parser.h
main.o        : carg_parser.h
