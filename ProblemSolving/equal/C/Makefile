CC=gcc
CFLAGS=-Wall -pedantic
LDFLAGS=
EXEC=main
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

main: main.o
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper:
	@rm -rf $(EXEC)
