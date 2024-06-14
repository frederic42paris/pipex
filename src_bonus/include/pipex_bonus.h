/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:45:23 by ftanon            #+#    #+#             */
/*   Updated: 2024/05/30 13:36:03 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include "../../printf/includes/ft_printf.h"

typedef struct s_pipd
{
	int		fd1;
	int		fd2;
	int		has_infile;	
	int		has_here_doc;
	int		argc;
	pid_t	*pids;
	int		counter;
	int		infile_access;
	int		outfile_access;
	char	*infile;
	char	*outfile;
	char	*limiter;
	int		exit_status;
	int		k;
}	t_pipd;

// 0. has_arguments
int		has_arguments(int argc);

// 1. store_basic_data
void	store_basic_data(t_pipd *pipd, int argc, char **argv);

// 2. argument_number
int		argument_number(t_pipd *pipd);

// 3. check_infile
void	check_infile(t_pipd *pipd);

// 4. open_infile
int		open_infile(t_pipd *pipd);

// 5. get_loop_start
void	get_loop_start(t_pipd *pipd);

// 6. handle_pipe
int		exec(char *cmd, char **envp, t_pipd *pipd);
void	single_pipe(char *argv, char **envp, t_pipd *pipd);

// 7. check_outfile
int		check_outfile(t_pipd *pipd);

// 8. open_outfile
void	open_outfile(t_pipd *pipd);

// 9. lastexec
void	lastexec(char *string, char **envp, t_pipd *pipd);

// 10. handle_wait
int		handle_wait(t_pipd *pipd);

// 11. handle_unlink
void	handle_unlink(t_pipd *pipd);

// 12. permission_denied
void	permission_denied(t_pipd *pipd);

// Utils
int		free_array(char **array);
void	free_pipd(t_pipd *pipd);

#endif