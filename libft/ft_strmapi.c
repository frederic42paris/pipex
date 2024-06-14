/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:29:51 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/29 16:23:19 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*array;
	size_t	i;
	size_t	length;

	if (s == 0)
		return (0);
	length = ft_strlen(s);
	i = 0;
	array = malloc(length * sizeof(char) + 1);
	if (array == NULL)
		return (0);
	while (i < length)
	{
		array[i] = f(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}

/* char f(unsigned int nb, char character)
{
return (character+nb);
}


int main ()
{
char string[]="1234";
char *array;
array = ft_strmapi(string,&f);
int i =0;

while(i<5)
{
printf("%c",*(array+i));
i++;
}
} */
