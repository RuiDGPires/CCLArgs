C_FILES := $(wildcard src/*.c)
H_FILES := $(wildcard include/*.h)
TEST := test.c
TARGET := a.out

$(TARGET): $(C_FILES) $(TEST) $(H_FILES)
	gcc -o $@ $(C_FILES) $(TEST)
