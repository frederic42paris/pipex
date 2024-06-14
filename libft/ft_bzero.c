/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:23 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/22 16:18:04 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}
/*
int main ()
{
int n;
char str[] = "hello";
int i;
int j;

n = 3;
i = 0;
j = 0;
while(i<5)
{
printf("%c",str[i]);
i++;
}
printf("\n");
ft_bzero(str,n);
while(j<5)
{
printf("%c",str[j]);
j++;
}
}
*/