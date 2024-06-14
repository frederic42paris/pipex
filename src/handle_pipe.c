/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:15:37 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/16 13:15:34 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

char	*env_path(char **envp)
{
	int			i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_path(char *paths_array, char **array_argv)
{
	char		*joined;
	char		*path;

	if (ft_strncmp(array_argv[0], "/", 1) == 0)
		path = array_argv[0];
	else
	{
		joined = ft_strjoin(paths_array, "/");
		path = ft_strjoin(joined, array_argv[0]);
	}
	if (access(path, R_OK) == 0)
		return (path);
	if (ft_strncmp(array_argv[0], "/", 1) != 0)
		free(joined);
	free(path);
	return (NULL);
}

char	*get_path(char **array_argv, char **envp)
{
	char		*paths_string;
	char		**paths_array;
	int			i;
	char		*result;

	paths_string = env_path(envp);
	if (paths_string != NULL)
	{
		paths_array = ft_split(paths_string, ':');
		i = 0;
		while (paths_array[i])
		{
			result = find_path(paths_array[i], array_argv);
			if (result != NULL)
				return (result);
			i++;
		}
		free_array(paths_array);
	}
	return (NULL);
}

int	exec(char *cmd, char **envp, t_pipd *pipd)
{
	char	**array_argv;
	char	*path_found;

	array_argv = ft_split(cmd, ' ');
	path_found = get_path(array_argv, envp);
	if (path_found == NULL)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(array_argv[0], 2);
		ft_putchar_fd('\n', 2);
		free_array(array_argv);
		free(pipd->pids);
		close(pipd->fd1);
		free(pipd);
		exit (127);
	}
	if (execve(path_found, array_argv, envp) == -1)
	{
		free_array(array_argv);
		free(pipd->pids);
		free(pipd);
		exit (1);
	}
	exit (0);
}

void	single_pipe(char *argv, char **envp, t_pipd *pipd)
{
	int		pipefd[2];
	pid_t	pid1;

	if (pipe(pipefd) == -1)
		exit(1);
	pid1 = fork();
	if (pid1 == -1)
		exit (1);
	if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		exec(argv, envp, pipd);
		close(pipd->fd1);
		exit(0);
	}
	pipd->pids[pipd->counter] = pid1;
	pipd->counter++;
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
}
