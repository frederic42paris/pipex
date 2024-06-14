/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infile_outfile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:15:37 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/14 18:04:45 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

int	infile_exist(char *string)
{
	if (access(string, F_OK) == -1)
	{
		perror(string);
		return (0);
	}
	return (1);
}

int	infile_rights(char *string)
{
	if (access(string, R_OK) == -1)
	{
		perror(string);
		return (0);
	}
	return (1);
}

void	check_infile(t_pipd *pipd)
{
	if (pipd->has_here_doc == 0)
	{
		pipd->has_infile = infile_exist(pipd->infile);
		if (pipd->has_infile == 1)
			pipd->infile_access = infile_rights(pipd->infile);
	}
}
