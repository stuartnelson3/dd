CFLAGS=-Wall -g

%: %.c
	cc $@.c -o $@
