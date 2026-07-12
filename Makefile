CC = clang
CFLAGS = -Wall -Wextra -std=c99
LIBS = -lraylib -lGL -lm -pthread -ldl -lrt

TARGET_DIR = build
TARGET = $(TARGET_DIR)/main
SRC = main.c $(shell find include -name "*.c")

$(TARGET): $(SRC)
	mkdir -p $(TARGET_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run
