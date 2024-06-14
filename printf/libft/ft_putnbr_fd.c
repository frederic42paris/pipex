/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:05 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/05 12:14:13 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	longnum;

	longnum = (long)n;
	if (longnum < 0)
	{
		ft_putchar_fd('-', fd);
		longnum = -longnum;
	}
	if (longnum > 9)
		ft_putnbr_fd(longnum / 10, fd);
	ft_putchar_fd(longnum % 10 + '0', fd);
}

/* int main ()
{
int fd;
int n;

n = 0;
fd = open("foo.txt", O_CREAT|O_WRONLY,0644);
if (fd < 0)
    perror("error");

ft_putnbr_fd(n, fd);
close(fd);
} */
