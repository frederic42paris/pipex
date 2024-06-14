/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:08 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/20 13:59:21 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main ()
{
int fd;
char c;

c = '2';
fd = open("foo.txt", O_CREAT|O_WRONLY, 0644);
if (fd < 0)
    perror("error");

ft_putchar_fd(c,fd);
close(fd);
}
*/