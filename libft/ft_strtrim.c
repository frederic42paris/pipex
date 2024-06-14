/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:28:43 by ftanon            #+#    #+#             */
/*   Updated: 2024/02/21 18:11:41 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*destination;
	int		malloclength;

	if (s1 == 0 || set == 0)
		return (0);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != 0)
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]) != 0)
		end--;
	if (s1[start] == '\0')
		malloclength = 1;
	else
		malloclength = end - start + 2;
	destination = (char *)malloc(sizeof(char) * (malloclength));
	if (destination == NULL)
		return (NULL);
	if (s1[start] == '\0')
		destination[0] = '\0';
	else
		ft_strlcpy(destination, s1 + start, end - start + 2);
	return (destination);
}

/*  int main ()
{
char const str[] = " salut ";
char const *set = " ";
printf("%s\n", ft_strtrim(str,set));
printf("%lu\n",strlen("tripouille") + 1);
}  */