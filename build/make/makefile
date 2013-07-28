ROOT_DIR ?= ../..
SRCROOT_DIR ?= $(ROOT_DIR)/src
SRC_DIR ?= $(SRCROOT_DIR)/source
HEAD_DIR ?= $(SRCROOT_DIR)/headers
OBJ_DIR ?= $(ROOT_DIR)/obj
BIN_DIR ?= $(ROOT_DIR)/bin

CLEAN_PATHS ?= $(OBJ_DIR) $(BIN_DIR)
RESULT_ITEMS ?= $(BIN_DIR)/wysiwyzbang.a

_OBJ = lib.o
OBJ = $(addprefix $(OBJ_DIR)/,$(_OBJ))

CC=gcc
CFLAGS=-I$(HEAD_DIR)

all: $(RESULT_ITEMS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD_DIR)/%.h $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(CLEAN_PATHS)

$(BIN_DIR)/wysiwyzbang.a: $(OBJ) $(BIN_DIR)
	ar rcs $(BIN_DIR)/wysiwyzbang.a $(OBJ)