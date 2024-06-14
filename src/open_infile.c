/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:15:37 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/14 17:39:11 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	receive_input(char *argv)
{
	char	*string;
	int		fd1;

	fd1 = open("temp", O_CREAT | O_WRONLY, 0644);
	while (1)
	{
		string = get_next_line(0);
		if (string == NULL
			|| ft_strncmp(string, argv, ft_strlen(string) - 1) == 0)
			break ;
		ft_putstr_fd(string, fd1);
		free(string);
	}
}

int	open_infile(t_pipd *pipd)
{
	int	fd1;

	if (pipd->has_here_doc == 1)
	{
		receive_input(pipd->limiter);
		fd1 = open("temp", O_CREAT | O_RDONLY, 0644);
	}
	else
	{
		if (pipd->has_infile == 0)
			fd1 = open(pipd->infile, O_CREAT, 0644);
		else if (pipd->has_infile == 1 && pipd->infile_access == 0)
			fd1 = open("temp", O_CREAT | O_RDONLY, 0644);
		else
			fd1 = open(pipd->infile, O_RDONLY);
	}
	dup2(fd1, 0);
	return (fd1);
}
