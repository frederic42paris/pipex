/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlen_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:15:01 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/07 17:06:02 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	longlonglen_unsigned(unsigned long long longnum, int base)
{
	int		size;

	size = 0;
	if (longnum == 0)
		return (1);
	while (longnum != 0)
	{
		size++;
		longnum = longnum / base;
	}
	return (size);
}
