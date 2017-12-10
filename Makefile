CC=g++
CFLAGS=-W -Wall -std=c++14 -pedantic
LDFLAGS=
EXEC=
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

main: main.o
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CC) -o $@ -c $< $(CLFAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper:
	@rm -rf $(EXEC)
