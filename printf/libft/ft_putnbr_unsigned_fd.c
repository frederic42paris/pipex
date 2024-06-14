/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:58:25 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/07 16:40:48 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_unsigned_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

/* int main ()
{
int fd;
int n;

n = -10;
fd = 1;
ft_unsignedputnbr_fd(n, fd);
}  */