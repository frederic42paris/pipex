/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:29:59 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/25 17:14:48 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*destination;
	int		i;
	size_t	length;

	i = 0;
	length = ft_strlen(source);
	destination = (char *)malloc(length +1);
	if (destination == NULL)
		return (NULL);
	while (source[i] != '\0')
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}

/* int main ()
{
char source[] = "";
char* target = ft_strdup(source); 
printf("%s", target);
} */
