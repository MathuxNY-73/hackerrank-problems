CXX=g++
CXFLAGS=-W -Wall -std=c++14 -pedantic
LDFLAGS=
EXEC=main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: $(EXEC)

main: main.o
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) -o $@ -c $< $(CXFLAGS)

main.o: solution.h

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
