/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:29:57 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/21 18:03:19 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		position;
	int		i;

	if (s1 == 0 || s2 == 0)
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	position = 0;
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
		dest[position++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		dest[position++] = s2[i++];
	dest[position] = '\0';
	return (dest);
}

/* int main ()
{
char *s1;
char *s2;

s1 = "salutd";
s2 = "cava";

printf("%s\n", ft_strjoin(s1, s2));
} */
