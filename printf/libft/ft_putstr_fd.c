/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:04 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/05 11:39:22 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != 0)
		write(fd, s, ft_strlen(s));
}

/* int main ()
{
int fd;
char string[]="salut";

fd = open("foo.txt", O_CREAT|O_WRONLY,0644);
if (fd < 0)
    perror("error");

ft_putstr_fd(string,fd);
close(fd);
} */
