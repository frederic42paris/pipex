/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_outfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:03:48 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/15 18:16:53 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	open_outfile(t_pipd *pipd)
{
	if (pipd->has_here_doc == 1)
		pipd->fd2 = open(pipd->outfile, O_CREAT | O_APPEND | O_WRONLY, 0644);
	else
		pipd->fd2 = open(pipd->outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	dup2(pipd->fd2, 1);
}
