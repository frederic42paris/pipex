/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:23:36 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/16 13:20:01 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipd	*pipd;
	int		exit_status;

	has_arguments(argc);
	pipd = malloc(sizeof(t_pipd));
	store_basic_data(pipd, argc, argv);
	argument_number(pipd);
	check_infile(pipd);
	pipd->fd1 = open_infile(pipd);
	get_loop_start(pipd);
	while (pipd->k < pipd->argc - 2)
		single_pipe(argv[pipd->k++], envp, pipd);
	close(pipd->fd1);
	pipd->outfile_access = check_outfile(pipd);
	if (pipd->outfile_access == 1)
	{
		open_outfile(pipd);
		lastexec(argv[pipd->argc - 2], envp, pipd);
		close(pipd->fd2);
	}
	exit_status = handle_wait(pipd);
	handle_unlink(pipd);
	permission_denied(pipd);
	free_pipd(pipd);
	exit(exit_status);
}
