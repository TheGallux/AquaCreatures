CC = gcc
CFLAGS= -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)
TARGET = aqua_creatures

all: build

build: $(OBJS)
	$(CC) $^ -o $(TARGET)

debug: CFLAGS += -g -fsanitize=address
debug: LDFLAGS += -fsanitize=address
debug: $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $(TARGET)

make_doxyfile:
	echo "PROJECT_NAME = \"Aqua Creatures\"" > Doxyfile
	echo "OUTPUT_DIRECTORY = docs" >> Doxyfile
	echo "INPUT = src" >> Doxyfile
	echo "RECURSIVE = YES" >> Doxyfile
	echo "FILE_PATTERNS = *.c *.h" >> Doxyfile
	echo "GENERATE_HTML = YES" >> Doxyfile
	echo "GENERATE_LATEX = NO" >> Doxyfile
	echo "EXTRACT_ALL = YES" >> Doxyfile

docs: make_doxyfile
	doxygen Doxyfile > /dev/null
	@echo "Generated documentation! Use 'open docs/html/index.html' to open it !"

clean:
	$(RM) $(OBJS) $(TARGET) Doxyfile Doxyfile.bak
	rm -rf docs

.PHONY: clean docs
