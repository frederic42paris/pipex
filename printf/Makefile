SRCS = ./libft/ft_putchar_fd.o \
./libft/ft_itoabase_unsigned.o \
./libft/ft_putstr_fd.o \
./libft/ft_putnbr_fd.o \
./libft/ft_putnbr_unsigned_fd.o \
./libft/ft_longlen.o \
./libft/ft_longlen_unsigned.o \
./libft/ft_strlen.o \
./printf/ft_printf.o \
./printf/ft_printf_diuxxp.o \
./printf/ft_printf_cs.o \

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(SRCS)
	ar rc $(NAME) $(SRCS)

%.o:%.c 
	cc -Wall -Wextra -Werror -o $@ -c $<

clean:
	rm -f $(SRCS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
