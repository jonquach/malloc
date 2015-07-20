##
## Makefile for  in /home/quach_a/Lab/malloc
## 
## Made by Jonathan Quach
## Login  <jonathan.quach@epitech.eu>
## 
## Started on  Wed Jan 28 14:50:10 2015 Jonathan Quach
## Last update Sun Feb 15 18:25:10 2015 Jonathan Quach
##

SRC =	malloc.c \
	page_alloc.c \
	realloc.c \
	free.c

TEST =	unit_test.c

OBJ =	$(SRC:.c=.o)

TEST_OBJ = $(TEST:.c=.o)

NAME =	libmy_malloc_$(HOSTTYPE).so

TEST_NAME = unit_test

RM =	rm -f

CC =	gcc

CFLAGS = -fPIC -W -Werror -Wextra -Wall

LDFLAGS = -shared

all:	 $(NAME)

$(NAME): $(OBJ)
	 $(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
	 ln -svf $(NAME) libmy_malloc.so

clean:
	 $(RM) $(OBJ)

fclean:  clean
	 $(RM) $(NAME)
	 $(RM) libmy_malloc.so

re:	 fclean all

test:	 $(OBJ) $(TEST_OBJ)
	 $(CC) -o $(TEST_NAME) $(OBJ) $(TEST_OBJ) $(CFLAGS)
	 ./unit_test
	 $(RM) $(TEST_NAME) $(OBJ) $(TEST_OBJ)

.PHONY:	 all clean fclean re test
