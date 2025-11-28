CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src
BUILD = build

OBJS = $(BUILD)/server.o $(BUILD)/client.o \
       $(BUILD)/util.o

all: server client

$(BUILD)/%.o: $(SRC)/%.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

server: $(BUILD)/server.o $(BUILD)/util.o
	$(CC) $(CFLAGS) $^ -o $(BUILD)/server

client: $(BUILD)/client.o $(BUILD)/util.o
	$(CC) $(CFLAGS) $^ -o $(BUILD)/client

clean:
	rm -rf $(BUILD)

.PHONY: all clean
