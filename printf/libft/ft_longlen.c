/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:57:26 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/07 16:18:34 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	longlen(long longnum, int base)
{
	int		size;

	size = 0;
	if (longnum == 0)
		return (1);
	else if (longnum < 0)
		size++;
	while (longnum != 0)
	{
		size++;
		longnum = longnum / base;
	}
	return (size);
}
