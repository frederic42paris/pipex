/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:05 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/22 17:29:36 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
