SUBDIRS = src

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
