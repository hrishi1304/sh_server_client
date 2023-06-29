	# Set the directories
INC_DIR := /home/hrishi1304/makefolder/inc
SRC_DIR := /home/hrishi1304/makefolder/src
BIN_DIR := /home/hrishi1304/makefolder/bin
LIB_DIR := /home/hrishi1304/makefolder/lib

# Specify the compiler and linker options
CC := gcc
CFLAGS := -I$(INC_DIR)
LDFLAGS := -shared

# Specify the source files and executables
SERVER_SRC := $(SRC_DIR)/server.c
CLIENT_SRC := $(SRC_DIR)/client.c
SERVER_BIN := $(BIN_DIR)/server
CLIENT_BIN := $(BIN_DIR)/client
LINKEDLIST_SRC := $(LIB_DIR)/linkedlist.c
LINKEDLIST_OBJ := $(LIB_DIR)/linkedlist.o
LINKEDLIST_SO := $(LIB_DIR)/liblinkedlist.so

.PHONY: all clean

all: $(SERVER_BIN) $(CLIENT_BIN) $(LINKEDLIST_SO)

$(SERVER_BIN): $(SERVER_SRC) $(LINKEDLIST_SO)
	$(CC) $(CFLAGS) $< -o $@ -L$(LIB_DIR) $(LDFLAGS) -llinkedlist

$(CLIENT_BIN): $(CLIENT_SRC) $(LINKEDLIST_SO)
	$(CC) $(CFLAGS) $< -o $@ -L$(LIB_DIR) $(LDFLAGS) -llinkedlist

$(LINKEDLIST_OBJ): $(LINKEDLIST_SRC)
	$(CC) $(CFLAGS) -c -fPIC $< -o $@

$(LINKEDLIST_SO): $(LINKEDLIST_OBJ)
	$(CC) $(LDFLAGS) $< -o $@

clean:
	rm -f $(SERVER_BIN) $(CLIENT_BIN) $(LINKEDLIST_OBJ) $(LINKEDLIST_SO)

