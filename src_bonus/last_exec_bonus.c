/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_exec_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:04:38 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/16 13:28:25 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex_bonus.h"

void	lastexec(char *string, char **envp, t_pipd *pipd)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 == -1)
	{
		exit (1);
	}
	if (pid1 == 0)
	{
		close(pipd->fd2);
		exec(string, envp, pipd);
	}
	pipd->pids[pipd->counter] = pid1;
	pipd->counter++;
}
