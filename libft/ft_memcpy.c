/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:12 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/29 16:20:14 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destination;
	char	*source;

	if (dest == 0 && src == 0)
		return (0);
	destination = (char *) dest;
	source = (char *) src;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
/* 
int main ()
{
int n;
char *src = NULL;
char dest[10];

n = 0;
ft_memcpy(dest,src,n);
printf("%s\n", src);
printf("%s\n", dest);
} */
