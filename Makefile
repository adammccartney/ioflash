.POSIX:
CROSS     =
CC        = $(CROSS)gcc
CFLAGS    = -Wall -Wextra -Og -g
LDFLAGS   =
LDLIBS    =

ioflash.exe: ioflash.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ ioflash.c $(LDLIBS)

clean:
	rm -f ioflash.exe error.log
