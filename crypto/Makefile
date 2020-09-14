CC=clang++ -std=c++17
LDFLAGS=-L/usr/local/opt/openssl@1.1/lib
CPPFLAGS=-I/usr/local/opt/openssl@1.1/include
LIBS=-lssl -lcrypto

all: main

main: main.cc openssl_ptr.h
	$(CC) $< $(CPPFLAGS) $(LDFLAGS) $(LIBS) -o $@ 

.PHONY: clean

clean:
	rm -f main 
