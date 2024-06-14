/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:01 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/22 12:51:55 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	while (*string != '\0' && *string != (char)searchedChar)
		string++;
	if (*string == '\0' && *string != (char)searchedChar)
		return (0);
	return ((char *)string);
}

/* int main ()
{
int searchedChar;
char str[]="salut";
searchedChar = 't' + 256;

printf("%s\n", ft_strchr(str,searchedChar));
printf("%s\n", strchr(str,searchedChar));
} */
