/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:29:45 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/29 16:17:15 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	if (length == 0)
		return (0);
	i = 0;
	while (first[i] != '\0' && second[i] != '\0'
		&& i < length -1 && first[i] == second[i])
	{
		i++;
	}
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}

/* int main ()
{
char first[]="t";
char second[]="";
size_t length;

length = 0;

printf("%d\n", ft_strncmp(first,second, length));
printf("%d\n",strncmp(first,second,length));
} */
