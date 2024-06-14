/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:07 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/22 17:14:04 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

/* int main ()
{
int fd;
char string[]="salut";

fd = open("foo.txt", O_CREAT|O_WRONLY,0644);
if (fd < 0)
    perror("error");

ft_putendl_fd(string,fd);
close(fd);
} */
