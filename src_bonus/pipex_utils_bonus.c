/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:09:49 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/16 13:28:36 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex_bonus.h"

void	displayarray(char **array)
{
	int			i;

	i = 0;
	while (array[i])
	{
		ft_putstr_fd(array[i], 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
}

int	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

void	free_pipd(t_pipd *pipd)
{
	free(pipd->pids);
	free(pipd);
}
