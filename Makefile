CFLAGS=-Wall -g

clean:
	rm -f ex1

%: %.c
	cc $@.c -o $@
