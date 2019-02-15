include config.mk

floattexter: main.c config.h
	$(CC) $(CFLAGS) -o floattexter main.c

clean:
	rm -fv floattexter
