/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:19 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/20 13:08:16 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int character)
{
	if (character >= 0 && character <= 127)
		return (1);
	else
		return (0);
}
/*
int main ()
{
int character;

character = 128;
printf("libc : %d\n", ft_isascii(character));
printf("own function : %d\n", isascii(character));
}
*/