/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:09 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/20 13:26:33 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*p;

	p = pointer;
	while (count > 0)
	{
		*p = value;
		p++;
		count--;
	}
	return (pointer);
}

/* int main ()
{
int n;
int c;
char str[] = "hello";

n = 3;
c = '$';
printf("%s\n",str);
ft_memset(str,c,n);
printf("%s\n",str);
} */
