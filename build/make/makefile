VAR_DIR ?= .

include $(VAR_DIR)/variables

all: $(RESULT_ITEMS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD_DIR)/%.h $(OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(CLEAN_PATHS)

$(BIN_DIR)/libwysiwyzbang.a: $(OBJ) $(BIN_DIR)
	ar rcs $(BIN_DIR)/libwysiwyzbang.a $(OBJ)

$(TB_OBJ_DIR)/%.o: $(TB_SRC_DIR)/%.c $(TB_OBJ_DIR)
	$(CC) -c -o $@ $< $(CFLAGS) 

$(TB_OBJ_DIR):
	mkdir -p $@

$(BIN_DIR)/wysiwyzbang-test-bin: $(TB_OBJ) $(TB_BIN_DIR) $(BIN_DIR)/libwysiwyzbang.a
	$(CC) -o $@ $< -L$(BIN_DIR) -lwysiwyzbang  