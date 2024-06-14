/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:29:40 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/29 16:11:17 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lenlittle;
	char	*typecastbig;

	if (big == 0 && len == 0)
		return (0);
	typecastbig = (char *)big;
	lenlittle = ft_strlen(little);
	if (lenlittle == 0)
		return (typecastbig);
	while (*typecastbig != '\0' && len > 0)
	{
		if (*typecastbig == *little
			&& ft_strncmp(typecastbig, little, lenlittle) == 0
			&& ft_strlen(typecastbig) >= lenlittle && len >= lenlittle)
			return (typecastbig);
		else
		{
			typecastbig++;
			len--;
		}
	}
	return (0);
}

/* int main ()
{
char largestr[30] = "aaabcabcd";
const char	*smallstr = "cd";
size_t  len;

len = 8;
printf("%s\n", ft_strnstr(largestr, smallstr, len));
printf("%s\n", strnstr(largestr,	smallstr, len));
} */
