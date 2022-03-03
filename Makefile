NAME			= push_swap
NAME_BONUS		= checker
CFLAGS			= -Wall -Wextra -Werror
CC				= gcc
HEADER			= push_swap.h
HEADER_BONUS	= checker.h
RM				= rm -f

SRCS 			=		push_swap.c algorithm.c commands01.c commands02.c commands03.c \
						first_sort.c memory.c sort_min.c sravnenie.c utils.c
SRCS_BONUS		=		checker.c commands01_bonus.c commands02_bonus.c commands03_bonus.c \
						errors_bonus.c utils_bonus.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS 			= ${SRCS:.c=.o}
OBJS_BONUS 		= ${SRCS_BONUS:.c=.o}

all: 		${NAME}

bonus:		${NAME_BONUS}

.c.o:
			${CC} ${CFLAGS}  -c $< -o ${<:.c=.o}

${NAME}: 		$(OBJS) $(HEADER)
				$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

${NAME_BONUS}:	$(OBJS_BONUS) $(HEADER_BONUS)
				$(CC) $(OBJS_BONUS) $(CFLAGS) -o $(NAME_BONUS)

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean: 	clean
			${RM} ${NAME} ${NAME_BONUS}

re: 		fclean all

.PHONY:		all clean fclean re bonus