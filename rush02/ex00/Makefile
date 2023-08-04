.PHONY: all clean fclean re

SRCS	=	check_arg.c		\
			ft_lib1.c		\
			ft_lib2.c		\
			ft_lib3.c		\
			main.c			\
			nbeditor1.c		\
			nbeditor2.c		\
			readfile.c		\
			pingpong.c

OBJS	= ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror
OUTPUT = rush-02

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${OUTPUT}: ${OBJS}
	${CC} -o ${OUTPUT} ${OBJS}

all: ${OUTPUT}

$(NAME): all

clean:
	rm -f *.o

fclean: clean
	rm -f $(OUTPUT)

re: fclean all
