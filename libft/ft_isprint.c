/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:30:16 by ftanon            #+#    #+#             */
/*   Updated: 2023/11/20 16:26:35 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int character)
{
	if (character >= 32 && character <= 126)
		return (1);
	else
		return (0);
}

/* int main ()
{
int character;

character = ' ' - 1;
printf("libc : %d\n", ft_isprint(character));
printf("own function : %d\n", isprint(character));
} */
