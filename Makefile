.POSIX
CC        = CC
CFLAGS    = -Wall -Wextra -Og -g
LDFLAGS   =
LDLIBS    =
EXE       = .exe

ioflash: ioflash.c
	$(CC) $(CFLAGS) ioflash.c -o ioflash

clean:
	rm -f ioflash error.log
