/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:11 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/23 13:37:33 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;
	int			i;

	destination = dest;
	source = src;
	if (source < destination)
	{
		i = (n - 1);
		while (i >= 0)
		{
			destination[i] = source[i];
			i--;
		}
	}
	else if (destination < source)
	{
		i = 0;
		while (i < (int)n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	return (destination);
}

/* int	main(void)
{
	int	n;
	char	src[] = {65, 66, 67, 68, 69, 0, 45};

	ft_memmove(src, src + 2, 2);
	printf("%s\n", src);
} */