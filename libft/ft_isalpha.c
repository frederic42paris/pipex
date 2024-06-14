/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:20 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/20 13:08:19 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if ((character >= 65 && character <= 90)
		|| (character >= 97 && character <= 122))
		return (1);
	else
		return (0);
}
/*
int main ()
{
    int character;
    character = '{';
    printf("libc : %d\n", ft_isalpha(character));
    printf("own function : %d\n", isalpha(character));
}
*/