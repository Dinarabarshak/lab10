CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11 -pedantic

BUILD_DIR = dist
SRC_DIR = src
TEST_DIR = test

MAIN_BIN = $(BUILD_DIR)/main.bin
TEST_BIN = $(BUILD_DIR)/test.bin

V_FLAGS=--tool=memcheck --leak-check=full --show-reachable=yes \
        --undef-value-errors=yes --track-origins=no --child-silent-after-fork=no \
        --trace-children=no --error-exitcode=1

.PHONY: all compile clean prep test leak-check

all: compile

compile: $(MAIN_BIN) $(TEST_BIN)

$(MAIN_BIN): $(BUILD_DIR)/main.o $(BUILD_DIR)/lib.o | prep
	$(CC) $(CFLAGS) $^ -o $@

$(TEST_BIN): $(BUILD_DIR)/test.o $(BUILD_DIR)/lib.o | prep
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/lib.h | prep
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

$(BUILD_DIR)/lib.o: $(SRC_DIR)/lib.c $(SRC_DIR)/lib.h | prep
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

$(BUILD_DIR)/test.o: $(TEST_DIR)/test.c $(SRC_DIR)/lib.h | prep
	$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

prep:
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(SRC_DIR)/*.o

leak-check: clean prep compile
	valgrind $(V_FLAGS) --log-file=$(BUILD_DIR)/valgrind_main.log --xml-file=$(BUILD_DIR)/valgrind_main.xml --xml=yes $(MAIN_BIN)
	valgrind $(V_FLAGS) --log-file=$(BUILD_DIR)/valgrind_test.log --xml-file=$(BUILD_DIR)/valgrind_test.xml --xml=yes $(TEST_BIN)

test: compile
	$(TEST_BIN)
