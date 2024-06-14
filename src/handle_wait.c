/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wait.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:15:37 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/16 12:16:12 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

int	handle_wait(t_pipd *pipd)
{
	int		i;
	int		status;

	i = 1;
	status = 0;
	while (pipd->pids[i])
	{
		waitpid(pipd->pids[i - 1], &status, 0);
		i++;
	}
	waitpid(pipd->pids[i - 1], &status, 0);
	return (WEXITSTATUS(status));
}
