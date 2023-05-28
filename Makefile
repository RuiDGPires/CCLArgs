TEST := test.c
TARGET := a.out
H_FILE := cclargs.h

$(TARGET): $(TEST) $(H_FILE)
	gcc -o $@ $(TEST)
