LIBFT_NAME = libft.a
LIBFT = libft
PRINTF = ft_printf
PRINTF_NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
all: $(LIBFT_NAME) $(PRINTF_NAME)
		gcc $(FLAG) server.c $(LIBFT_NAME) $(PRINTF_NAME) -o server
		gcc $(FLAG) client.c $(LIBFT_NAME) $(PRINTF_NAME) -o client
$(LIBFT_NAME) $(PRINTF_NAME): $(LIBFT) $(PRINTF)
		make -C $(LIBFT)
		make -C $(PRINTF)
		cp libft/libft.a .
		cp ft_printf/libftprintf.a .
clean:
		make clean -C $(LIBFT)
		make clean -C $(PRINTF)
fclean: clean
		make fclean -C $(LIBFT)
		make fclean -C $(PRINTF)
		rm -rf $(LIBFT_NAME)
		rm -rf $(PRINTF_NAME)
		rm -rf server client
re: fclean all

.PHONY: clean fclean all