/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:22:00 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/06 14:56:26 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printfcase(int *ptrlength, char character, va_list args)
{
	if (character == 'c')
		ft_printc(va_arg(args, int), ptrlength);
	else if (character == 's')
		ft_prints(va_arg(args, char *), ptrlength);
	else if (character == 'p')
		ft_printp(va_arg(args, unsigned long long), ptrlength);
	else if (character == 'd' || character == 'i')
		ft_printdi(va_arg(args, int), ptrlength);
	else if (character == 'u')
		ft_printu(va_arg(args, unsigned int), ptrlength);
	else if (character == 'x')
		ft_printxx(va_arg(args, unsigned int), 'x', ptrlength);
	else if (character == 'X')
		ft_printxx(va_arg(args, unsigned int), 'X', ptrlength);
	else if (character == '%')
		ft_printc('%', ptrlength);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	int				i;
	int				length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			printfcase(&length, str[i], args);
		}
		else
		{
			write(1, str + i, 1);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}

/* int	main(void)
{
	ft_printf("%s", "hello");
	printf(" %s", "");
	
	ft_printf("%c %s %p %d %i %u %x %X %%\n",
		'c', "hello", "hey", 12, 13, 15, 123, 123);
	printf("%c %s %p %d %i %u %x %X %%\n",
		'c', "hello", "hey", 12, 13, 15, 123, 123);
} */
/* int	main(void)
{
	printf(" %d", ft_printf("%p", LONG_MAX));
	printf("\n");
	printf(" %d", printf("%p", LONG_MAX));
} */
/* 	printf("own %d\n",ft_printf("%c %s %p %d %i %u %x %X %%\n",
		'c', "hello", "hey", 12, 13, 15, 123, 123));
	printf("std %d\n",printf("%c %s %p %d %i %u %x %X %%\n",
		'c', "hello", "hey", 12, 13, 15, 123, 123)); */

/* 	%s
	printf("%d",ft_printf(" NULL %s NULL ", NULL));
	printf("\n");
	printf("%d",printf(" NULL %s NULL ", NULL)); */