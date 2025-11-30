CC = clang
CFLAGS = -Wall -Wextra -std=c11
OBJ = src/main.o src/lib.o
BIN = bin/app

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

src/main.o: src/main.c src/lib.h
	$(CC) $(CFLAGS) -c src/main.c -o src/main.o

src/lib.o: src/lib.c src/lib.h
	$(CC) $(CFLAGS) -c src/lib.c -o src/lib.o

clean:
	rm -f src/*.o
	rm -f $(BIN)
