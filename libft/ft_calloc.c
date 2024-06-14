/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:22 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/21 17:02:44 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h> 
#include <sys/time.h>
#include <sys/resource.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memoryallocated;
	size_t	totalsize;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((int)nmemb < 0 || (int)size < 0
		|| (int)nmemb > INT_MAX || (int)size > INT_MAX)
		return (NULL);
	totalsize = nmemb * size;
	memoryallocated = malloc(totalsize);
	if (memoryallocated == NULL)
	{
		return (NULL);
	}
	else
	{
		ft_memset(memoryallocated, 0, totalsize);
	}
	return (memoryallocated);
}

/* int main()
{
	int		*ptr;
	int		n;
	int		i;
	int		size;

	n = -5;
	size = 0;

	i = 0;
	printf("elements: %d // size: %d\n", n, size);
	printf("\n");
	ptr = (int *)ft_calloc(n, sizeof(int));
	if (ptr == NULL)
	{
		printf("Memory not allocated.\n");
		exit(0);
	}
	else
	{
		printf("SUCCESS\n");
		while (i < n)
		{
			ptr[i] = i + 1;
			i++;
		}
		printf("array: ");
		i = 0;
		while (i < n)
		{
			printf("%d, ", ptr[i]);
			i++;
		}

	}
	return (0);
} */
