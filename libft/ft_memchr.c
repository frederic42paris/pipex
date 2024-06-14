/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:14 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/23 14:29:34 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	size_t		i;
	char		*memoryarray;

	if (size == 0)
		return (NULL);
	memoryarray = (char *)memoryBlock;
	i = 0;
	while (i < size)
	{
		if (memoryarray[i] == (char)searchedChar)
			return ((char *)memoryBlock + i);
		i++;
	}
	return (NULL);
}

/*  int main ()
{
char data[] = {0, 1, 2 ,3 ,4 ,5};
int searchedChar = 256;
size_t size = 3;

void *ownfound = ft_memchr( data, searchedChar, size );
printf( "%s\n", ( ownfound != NULL ? "found" : "not found" ) );

void *stdfound = memchr( data, searchedChar, size );
printf( "%s\n", ( stdfound != NULL ? "found" : "not found" ) );
}  */
