/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:13 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/23 14:29:02 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buff1, const void *buff2, size_t count)
{
	size_t			i;
	unsigned char	*buffer1;
	unsigned char	*buffer2;

	buffer1 = (unsigned char *)buff1;
	buffer2 = (unsigned char *)buff2;
	i = 0;
	if (count <= 0)
		return (0);
	while (i < count - 1 && buffer1[i] == buffer2[i])
		i++;
	return (buffer1[i] - buffer2[i]);
}

/* int main ()
{
char buff1[] = {0, 0, 127, 0};
char buff2[] = {0, 0, 42, 0};

int a;

a = 4;
printf("%d\n", ft_memcmp(buff1, buff2, a));
printf("%d\n", memcmp(buff1, buff2, a));
} */
