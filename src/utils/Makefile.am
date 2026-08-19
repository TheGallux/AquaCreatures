# Name of the libaries
lib_LIBRARIES = libutils.a

# List of file to compile in libutils.a
libutils_a_SOURCES =  \
	double_matrix/double_matrix.h \
	double_matrix/double_matrix_allocation.c \
	double_matrix/double_matrix_miscellaneous.c \
	double_matrix/double_matrix_operations_single.c \
	double_matrix/double_matrix_operations_double.c

libutils_a_CPPFLAGS = -I$(top_srcdir)/src

libutils_a_CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

noinst_LIBRARIES = libutils.a

