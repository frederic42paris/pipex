/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:29:36 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/22 12:41:17 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	i;

	i = ft_strlen(string);
	while (i > 0 && string[i] != (char)searchedChar)
		i--;
	if (i == 0 && string[i] != (char)searchedChar)
		return (0);
	return ((char *)string + i);
}
/*
int main ()
{
int searchedChar;
char str[]="sllut";
searchedChar = 'p';

printf("%s\n", ft_strrchr(str,searchedChar));
printf("%s\n", strrchr(str,searchedChar));
}
*/