
FILE=studentreg
CC = gcc
CC_FLAGS = -Wall -ansi -pedantic
OUT_EXE = labAssesment3
file: $(FILE)

	./$(OUT_EXE) 

$(FILE): $(FILE).o $(MODS)
	$(CC) $(FILELDFLAGS) -o $(OUT_EXE) $^ 

$(OUT_EXE).o: $(FILE).c
	$(CC) -c  $< $(CC_FLAGS)