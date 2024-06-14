/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:58:04 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/07 16:48:00 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printc(int character, int *ptrlength)
{
	ft_putchar_fd(character, 1);
	(*ptrlength)++;
}

void	ft_prints(char *string, int *ptrlength)
{
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*ptrlength = *ptrlength + 6;
	}
	else
	{
		ft_putstr_fd(string, 1);
		*ptrlength = *ptrlength + strlen(string);
	}
}
