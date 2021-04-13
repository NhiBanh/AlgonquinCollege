CC=gcc
FILE1=linked_list.c
FILE2=populate_file.c
FILE3=random_file_access.c
OUT_EXE1=linked_list
OUT_EXE2=populate_file
OUT_EXE3=random_file_access
CFLAGS=-g -ansi -pedantic -Wall -w

all: build1 build2 build3 run1

build1: $(FILE1)
	$(CC)	-o	$(OUT_EXE1)		$(FILE1)

build2: $(FILE2)
	$(CC)	-o		$(OUT_EXE2)		$(FILE2)

build3: $(FILE3)
	$(CC)		-o		$(OUT_EXE3)		$(FILE3)

run1: ./$(OUT_EXE1)