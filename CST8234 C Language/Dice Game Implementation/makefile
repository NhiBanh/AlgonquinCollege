CC= gcc
CFLAGS = -Wall -ansi -pedantic
TARGET = dicegame
RM = rm
SOURCES = banh0007_A1.c dicegame.c
OBJECTS = $(SOURCES:.c=.o)

.PHONY: all clean

all: $(TARGET)

clean:
	$(RM)	$(TARGET)	$(OBJECTS)

$(TARGET)	:	$(OBJECTS)
	$(CC)	$^	-o	$@

%.o:	%.c
	$(CC)	$(CFLAGS)	-c	$<