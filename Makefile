CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_C = client.c
OBJS_C = $(SRCS_C:.c=.o)

SRCS_S = server.c
OBJS_S = $(SRCS_S:.c=.o)

SRCS_BONUS_C = client_bonus.c
OBJS_BONUS_C = $(SRCS_BONUS_C:.c=.o)

SRCS_BONUS_S = server_bonus.c server_help_bonus.c
OBJS_BONUS_S = $(SRCS_BONUS_S:.c=.o)

NAME_C = client
NAME_S = server
NAME_BONUS_C = client_bonus
NAME_BONUS_S = server_bonus
HEADER = minitalk.h
HEADER_BONUS = minitalk_bonus.h


all: $(NAME_C) $(NAME_S)

bonus: $(NAME_BONUS_C) $(NAME_BONUS_S)

$(NAME_C): $(OBJS_C)
	$(CC) $(CFLAGS) $(OBJS_C) -o $(NAME_C)

$(NAME_S): $(OBJS_S)
	$(CC) $(CFLAGS) $(OBJS_S) -o $(NAME_S)

$(NAME_BONUS_C): $(OBJS_BONUS_C)
	$(CC) $(CFLAGS) $(OBJS_BONUS_C) -o $(NAME_BONUS_C)

$(NAME_BONUS_S): $(OBJS_BONUS_S)
	$(CC) $(CFLAGS) $(OBJS_BONUS_S) -o $(NAME_BONUS_S)
              
%_bonus.o: %_bonus.c $(HEADER_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_C) $(OBJS_S) $(OBJS_BONUS_C) $(OBJS_BONUS_S)

fclean: clean
	rm -f $(NAME_C) $(NAME_S) $(NAME_BONUS_C) $(NAME_BONUS_S)

re: fclean all

.PHONY: all clean fclean re bonus