CC=gcc
CFLAGS=-w

hellomake: usemem.c
	$(CC) $(CFLAGS) -o usemem usemem.c

clean:
	rm usemem
