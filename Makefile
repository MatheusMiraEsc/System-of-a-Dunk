CC = gcc
CFLAGS = -Iinclude -Wall
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = system-of-a-dunk

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

