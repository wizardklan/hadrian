# Depends on LLVM (Clang) toolchain
# https://github.com/llvm/llvm-project/releases/latest

NAME := hadrian

CC      := clang
AR      := llvm-ar
RANLIB  := llvm-ranlib

CFLAGS   := -std=c99 -Wall -Wextra -Wpedantic -O2 -g
PICFLAGS := -fPIC

BUILD    := build
OBJ      := $(BUILD)/obj
OBJ_PIC  := $(BUILD)/obj_pic
BIN      := $(BUILD)/bin
TESTBIN  := $(BUILD)/tests

SRC_DIR  := src
INC_DIR  := include
TEST_DIR := tests

SRCS     := $(wildcard $(SRC_DIR)/*.c)
OBJS     := $(SRCS:$(SRC_DIR)/%.c=$(OBJ)/%.o)
PIC_OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_PIC)/%.o)

TEST_SRCS := $(wildcard $(TEST_DIR)/*.c)


ifeq ($(OS),Windows_NT)

STATIC_LIB := $(BIN)/lib$(NAME).a
SHARED_LIB := $(BIN)/$(NAME).dll
SHARED_FLAGS := -shared -Wl,--out-implib,$(BIN)/lib$(NAME).dll.a

TEST_EXT := .exe
MKDIR := mkdir
RM := rmdir /S /Q

else

UNAME := $(shell uname -s)

STATIC_LIB := $(BIN)/lib$(NAME).a

ifeq ($(UNAME),Darwin)
SHARED_LIB := $(BIN)/lib$(NAME).dylib
SHARED_FLAGS := -dynamiclib
else
SHARED_LIB := $(BIN)/lib$(NAME).so
SHARED_FLAGS := -shared
endif

TEST_EXT :=
MKDIR := mkdir -p
RM := rm -rf

endif


.PHONY: static dynamic tests clean


# Directory creation

$(OBJ) $(OBJ_PIC) $(BIN) $(TESTBIN):
	$(MKDIR) $@


# Static library

static: $(STATIC_LIB)

$(STATIC_LIB): $(OBJS) | $(BIN)
	$(AR) rcs $@ $^
	$(RANLIB) $@


# Dynamic library

dynamic: $(SHARED_LIB)

$(SHARED_LIB): $(PIC_OBJS) | $(BIN)
	$(CC) $(SHARED_FLAGS) -o $@ $^


# Object files

$(OBJ)/%.o: $(SRC_DIR)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@


$(OBJ_PIC)/%.o: $(SRC_DIR)/%.c | $(OBJ_PIC)
	$(CC) $(CFLAGS) $(PICFLAGS) -I$(INC_DIR) -c $< -o $@


# Tests

tests: $(TESTBIN)
	@for f in $(TEST_SRCS); do \
		name=$$(basename $$f .c); \
		$(CC) $(CFLAGS) -I$(INC_DIR) $$f $(SRCS) \
			-o $(TESTBIN)/$$name$(TEST_EXT); \
	done


# Clean

clean:
	$(RM) $(BUILD)
