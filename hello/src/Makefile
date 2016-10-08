CC = clang
CFLAGS = -Wall -g -O2

all: helloworld

helloworld: helloworld.c
	$(CC) $(CFLAGS) $< -o $@

check: helloworld
	./helloworld

clean:
	rm -f helloworld
	rm -fr *.dSYM
