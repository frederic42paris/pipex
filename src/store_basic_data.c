/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_basic_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:15:37 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/15 13:13:36 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

int	check_here_doc(char *argv)
{
	if (ft_strncmp(argv, "here_doc", ft_strlen(argv)) == 0)
		return (1);
	else
		return (0);
}

void	store_basic_data(t_pipd *pipd, int argc, char **argv)
{
	int	i;

	i = 0;
	pipd->argc = argc;
	pipd->has_here_doc = check_here_doc(argv[1]);
	if (pipd->has_here_doc == 0)
		pipd->infile = argv[1];
	else
		pipd->limiter = argv[2];
	pipd->outfile = argv[argc - 1];
	pipd->pids = malloc(sizeof(pid_t) * (pipd->argc - 3 + 1));
	while (i < pipd->argc - 3 + 1)
	{
		pipd->pids[i] = 0;
		i++;
	}
	pipd->counter = 0;
}
