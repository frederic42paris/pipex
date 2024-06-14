/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:15:15 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/07 17:07:53 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*copynum(unsigned long long num, int len, char *baselist, int base)
{
	char	*string;
	int		index;

	string = (char *)malloc((len + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[len] = '\0';
	len--;
	if (num == 0)
		string[0] = '0';
	while (num != 0)
	{
		index = num % base;
		string[len] = baselist[index];
		num = num / base;
		len--;
	}
	return (string);
}

char	*ft_itoabase_unsigned(unsigned long long num, char *baselist, int base)
{
	char				*string;
	int					length;

	length = longlonglen_unsigned(num, base);
	string = copynum(num, length, baselist, base);
	return (string);
}
