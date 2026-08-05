CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = do-op
SRCS = srcs/ft_atoi.c srcs/ft_putnbr.c srcs/main.c srcs/math.c 
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : fclean clean all re
