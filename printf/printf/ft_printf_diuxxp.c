/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_diuxxp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:58:21 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/07 17:06:27 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printdi(int number, int	*ptrlength)
{
	ft_putnbr_fd(number, 1);
	*ptrlength = *ptrlength + longlen(number, 10);
}

void	ft_printu(unsigned int number, int *ptrlength)
{
	ft_putnbr_unsigned_fd(number, 1);
	*ptrlength = *ptrlength + longlen(number, 10);
}

void	ft_printp(unsigned long long num, int *ptrlength)
{
	char				*baselist;
	char				*string;
	int					length;

	baselist = "0123456789abcdef";
	if (num == 0)
	{
		ft_putstr_fd("(nil)", 1);
		*ptrlength = *ptrlength + 5;
	}
	else
	{
		length = longlonglen_unsigned(num, 16);
		string = ft_itoabase_unsigned(num, baselist, 16);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(string, 1);
		free(string);
		*ptrlength = *ptrlength + length + 2;
	}
}

void	ft_printxx(unsigned int num, char x, int *ptrlength)
{
	char			*string;
	int				length;
	char			*baselist;

	if (x == 'x')
		baselist = "0123456789abcdef";
	else
		baselist = "0123456789ABCDEF";
	length = longlonglen_unsigned(num, 16);
	string = ft_itoabase_unsigned(num, baselist, 16);
	ft_putstr_fd(string, 1);
	free(string);
	*ptrlength = *ptrlength + length;
}

/* void	ft_printp(unsigned long long num, int *ptrlength)
{
	char				*hexdigits;
	unsigned long long	divider;
	int					length;

	divider = 1;
	length = 0;
	hexdigits = "0123456789abcdef";
	if (num == 0)
	{
		ft_putstr_fd("(nil)", 1);
		*ptrlength = *ptrlength + 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		while (divider * 16 <= num)
			divider = divider * 16;
		while (divider != 0)
		{
			ft_putchar_fd(hexdigits[num / divider], 1);
			num = num % divider;
			divider = divider / 16;
			length++;
		}
		*ptrlength = *ptrlength + length +2;
	}
}

void	ft_printxx(unsigned int num, char x, int *ptrlength)
{
	char			*hexdigits;
	long			divider;
	int				length;

	divider = 1;
	length = 0;
	if (x == 'x')
		hexdigits = "0123456789abcdef";
	else
		hexdigits = "0123456789ABCDEF";
	while (divider * 16 <= num)
		divider = divider * 16;
	while (divider != 0)
	{
		ft_putchar_fd(hexdigits[num / divider], 1);
		num = num % divider;
		divider = divider / 16;
		length++;
	}
	*ptrlength = *ptrlength + length;
} */