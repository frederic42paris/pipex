/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:25 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/02 16:25:29 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *string)
{
	int	result;
	int	i;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (string[i] == ' ' || string[i] == '\f'
		|| string[i] == '\n' || string[i] == '\r'
		|| string[i] == '\t' || string[i] == '\v')
	i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (string[i] != '\0' && string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + string[i] - '0';
		i++;
	}
	return (result * sign);
}

/* int main ()
{
const char *str;

str = "2147483667";
printf("%d\n", ft_atoi(str));
printf("%d\n", atoi(str));
} */
