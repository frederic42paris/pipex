/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:29:56 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/29 16:16:03 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	finalsize;

	if (dest == 0 && size == 0)
		return (0);
	if (size < ft_strlen(dest))
		finalsize = size + ft_strlen(src);
	else
		finalsize = ft_strlen(src) + ft_strlen(dest);
	i = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	if (size > 0)
	{
		while (src[k] != '\0' && i < size - 1)
		{
			dest[i] = src[k];
			i++;
			k++;
		}
		dest[i] = '\0';
	}
	return (finalsize);
}

/* int main ()
{
	char stddest[30] ;
	char owndest[30] ;
	char stdsrc[] = "AAAAAAA";
	char ownsrc[] = "AAAAAAA";
	int n;

	n = -1;
	printf("size %d\n", n);
	printf("\n");

	printf("standard function : \n");
	printf("%zu\n", strlcat(stddest,stdsrc,n));
	printf("%s\n", stddest);
	printf("%s\n", stdsrc);

	printf("\n");

	printf("own function : \n");
	printf("%zu\n", ft_strlcat(owndest,ownsrc,n));
	printf("%s\n", owndest);
	printf("%s\n", ownsrc);
} */
