/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:21 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/20 13:08:21 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if (ft_isalpha(character) > 0 || ft_isdigit(character) > 0)
		return (1);
	else
		return (0);
}
/*
int main ()
{
int character;

character = 'a';
printf("libc : %d\n", ft_isalnum(character));
printf("own function : %d\n", isalnum(character));
}
*/