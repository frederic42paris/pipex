/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:29:58 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/22 12:16:06 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}

/* void f(unsigned int index, char* string)
{
    *string = *string + index;
}


int main ()
{
char string[]="0000000000";
ft_striteri(string,&f);
int i =0;

while(i<10)
{
printf("%c",string[i]);
i++;
}
}
 */