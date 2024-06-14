/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:29:11 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/26 13:00:42 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;
	int		malloclength;

	malloclength = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		malloclength = 0;
	else if (len > ft_strlen(s) - start + 1)
		malloclength = ft_strlen(s) - start;
	else
		malloclength = len;
	dest = (char *)malloc(sizeof(char) * (malloclength +1));
	if (dest == NULL)
		return (NULL);
	while (i < malloclength && s[start] != '\0')
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

/* int main ()
{
char source[] = "";
int start = 1;
size_t len = 1;
printf("%s\n",ft_substr(source, start, len));
} */