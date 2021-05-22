CC=gcc
CFLAGS=-Wall -g 

ioflash: ioflash.c
	$(CC) $(CFLAGS) ioflash.c -o ioflash

clean:
	rm -f ioflash
