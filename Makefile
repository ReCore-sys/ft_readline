# the compiler: gcc for C program, define as g++ for C++
CC = cc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -Werror -Wextra

all:
	$(CC) $(CFLAGS) get_next_line.c get_next_line_utils.c get_next_line.h -Ddo_exe

clean:
	$(RM) get_next_line.o

fclean: clean

re: fclean all

.PHONY: all clean fclean re