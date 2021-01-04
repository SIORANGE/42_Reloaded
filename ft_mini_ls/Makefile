NAME = ft_mini_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = ./include/ft_mini_ls.h

SRCFILE = ./src/main.c\
			./src/ft_lstadd_back.c\
			./src/ft_lstadd_previous.c\
			./src/ft_lstfree.c\
			./src/ft_lstfront.c\
			./src/ft_lstlast.c\
			./src/ft_lstnew.c\
			./src/ft_strcmp.c\
			./src/ft_strjoin.c\
			./src/ft_strlcat.c\
			./src/ft_strlcpy.c\
			./src/ft_strlen.c\
			./src/ft_which_to_insert.c

OBJECTS	= ${SRCFILE:.c=.o}

.c.o :
		${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): ${OBJECTS}
		$(CC) $(CFLAGS) -o $(NAME) ${OBJECTS}

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
