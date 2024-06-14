/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_number_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:15:37 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/16 13:28:09 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex_bonus.h"

int	argument_number(t_pipd *pipd)
{
	if (pipd->has_here_doc == 0 && pipd->argc < 5)
	{
		ft_printf("Number of arguments incorrect\n");
		free_pipd(pipd);
		exit(1);
	}
	else if (pipd->has_here_doc == 1 && pipd->argc < 6)
	{
		ft_printf("Number of arguments incorrect\n");
		free_pipd(pipd);
		exit(1);
	}
	return (0);
}

int	has_arguments(int argc)
{
	if (argc < 2)
		exit(1);
	return (0);
}
