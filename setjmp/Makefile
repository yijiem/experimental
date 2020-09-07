CC=clang

all: setjmp_vars setjmp_vars.s

setjmp_vars: setjmp_vars.c
	$(CC) -o $@ $< $(CFLAGS)

setjmp_vars.s: setjmp_vars.c
	$(CC) -S $< -o $@ $(CFLAGS)

.PHONY: clean

clean:
	rm -f setjmp_vars setjmp_vars.s
