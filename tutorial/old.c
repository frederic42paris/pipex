/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:26:21 by ftanon            #+#    #+#             */
/*   Updated: 2024/04/13 18:08:06 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// char *env_path2(char **envp)
// {
// 	int i;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (ft_strncmp(envp[i], "PATH", 4) == 0)
// 			return (envp[i] + 5);
// 	i++;
// 	}
// 	return (NULL);
// }

// char *get_path2(char **array_argv, char **envp)
// {
// 	char *paths_string;
// 	char **paths_array;
// 	int i;
// 	char *joined;
// 	char *path;

// 	paths_string = env_path2(envp);
// 	if (paths_string != NULL)
// 	{
// 	paths_array = ft_split(paths_string, ':');
// 	i = 0;
// 		while (paths_array[i])
// 		{
// 			joined = ft_strjoin(paths_array[i], "/");
// 			path = ft_strjoin(joined, array_argv[0]);
// 			if (access(path, R_OK) == 0)
// 				return (path);
// 			i++;
// 			free(joined);
// 			free(path);
// 		}
// 		free_array(paths_array);
// 	}
// 	return (NULL);
// }

// void lastexec2(char **envp, char **string)
// {
// 	int pipefd1[2];
// 	int pipefd2[2];
// 	int pipefd3[2];
// 	char **parsearg;
// 	char *path_found;
// 	pid_t pid1;
// 	pid_t pid2;
// 	pid_t pid3;
// 	pid_t pid4;

// 	pipe(pipefd1);
// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		dprintf(2, "1\n");
// 		close(pipefd1[0]);
// 		dup2(pipefd1[1], 1);
// 		parsearg = ft_split(string[2], ' ');
// 		path_found = get_path2(parsearg, envp);
// 		if (path_found == NULL)
// 		{
// 			dprintf(2,"%s not found \n", string[2]);
// 		}
// 		execve(path_found, parsearg, envp);
// 		exit(0);
// 	}
// 	waitpid(pid1, NULL, WNOHANG);
// 	// waitpid(-1, NULL, WNOHANG);
// 	// wait(NULL);
// 	close(pipefd1[1]);
// 	dup2(pipefd1[0], 0);

// 	pipe(pipefd2);
// 	pid2 = fork();
// 	if (pid2 == 0)
// 	{
// 		dprintf(2, "2\n");
// 		close(pipefd2[0]);
// 		dup2(pipefd2[1], 1);
// 		parsearg = ft_split(string[3], ' ');
// 		path_found = get_path2(parsearg, envp);
// 		if (path_found == NULL)
// 		{
// 			dprintf(2,"%s not found \n", string[3]);
// 		}
// 		execve(path_found, parsearg, envp);
// 		exit(0);
// 	}
// 	waitpid(pid2, NULL, 0);
// 	// waitpid(-1, NULL, 0);
// 	// wait(NULL);
// 	close(pipefd2[1]);
// 	dup2(pipefd2[0], 0);

// 	pipe(pipefd3);
// 	pid3 = fork();
// 	if (pid3 == 0)
// 	{
// 		dprintf(2, "3\n");
// 		close(pipefd3[0]);
// 		dup2(pipefd3[1], 1);
// 		parsearg = ft_split(string[4], ' ');
// 		path_found = get_path2(parsearg, envp);
// 		if (path_found == NULL)
// 		{
// 			dprintf(2,"%s not found \n", string[4]);
// 		}
// 		execve(path_found, parsearg, envp);
// 		exit(0);
// 	}
// 	waitpid(pid3, NULL, 0);
// 	// waitpid(-1, NULL, 0);
// 	// wait(NULL);
// 	close(pipefd3[1]);
// 	dup2(pipefd3[0], 0);

// 	pid4 = fork();
// 	if (pid4 == 0)
// 	{
// 		dprintf(2, "4\n");
// 		parsearg = ft_split(string[5], ' ');
// 		path_found = get_path2(parsearg, envp);
// 		if (path_found == NULL)
// 		{
// 			dprintf(2,"%s not found \n", string[5]);
// 		}
// 		execve(path_found, parsearg, envp);
// 		exit(0);
// 	}
// 	waitpid(pid4, NULL, 0);
// 	// waitpid(-1, NULL, 0);
// 	// wait(NULL);

// 	// wait(NULL);
// 	// wait(NULL);
// 	// wait(NULL);
// 	// wait(NULL);
// 	// waitpid(-1, NULL, 0);
// 	// waitpid(-1, NULL, 0);
// 	// waitpid(-1, NULL, 0);
// 	// waitpid(-1, NULL, 0);
// 	// waitpid(pid1, NULL, WUNTRACED);
// 	// waitpid(pid2, NULL, 0);
// 	// waitpid(pid3, NULL, 0);
// 	// waitpid(pid4, NULL, 0);
// }

// int main(int argc, char **argv, char **envp)
// {
// 	int fd1;

// 	printf("argc %d\n", argc);
// 	fd1 = open(argv[1], O_RDONLY);
// 	dup2(fd1, 0);
// 	lastexec2(envp, argv);
// 	// lastexec3(argv[argc - 1], envp);
// 	// dprintf(2, "[0]\n");
// 	close(fd1);
// }

// void	lastexec2(char **envp, char **string)
// {
// 	int pipefd[2];
// 	char	**parsearg;
// 	char	*path_found;
// 	pid_t	pid1;
// 	pid_t	pid2;
// 	pid_t	pid3;
// 	pid_t	pid4;
// 	pid_t	pid5;

// 	// printf("%s %s\n", string[0], envp[0]);
// 	pipe(pipefd);
// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		dprintf(2, "1\n");
// 		close(pipefd[0]);
// 		dup2(pipefd[1], 1);
// 		parsearg = ft_split(string[2], ' ');
// 		path_found = get_path(parsearg, envp);
// 		execve(path_found, parsearg, envp);
// 		exit(0);
// 	}

// 	pid2 = fork();
// 	if (pid2 == 0)
// 	{
// 		dprintf(2, "2\n");
// 		close(pipefd[1]);
// 		dup2(pipefd[0], 0);
// 		parsearg = ft_split(string[3], ' ');
// 		path_found = get_path(parsearg, envp);
// 		execve(path_found, parsearg, envp);
// 		exit(0);
// 	}
// 	pid3 = fork();
// 	if (pid3 == 0)
// 	{
// 		dprintf(2, "3\n");
// 		exit(0);
// 	}
// 	pid4 = fork();
// 	if (pid4 == 0)
// 	{
// 		dprintf(2, "4\n");
// 		exit(0);
// 	}
// 	pid5 = fork();
// 	if (pid5 == 0)
// 	{
// 		dprintf(2, "5\n");
// 		exit(0);
// 	}

// 	// wait(NULL);
// 	wait(NULL);
// 	wait(NULL);
// 	wait(NULL);
// 	dprintf(2, "0\n");
// 	// close(pipefd[1]);
// 	// dup2(pipefd[0], 0);
// 	// parsearg = ft_split(string[3], ' ');
// 	// path_found = get_path(parsearg, envp);
// 	// execve(path_found, parsearg, envp);
// }

// char	*env_path2(char **envp)
// {
// 	int			i;

// 	i = 0;
// 	while (envp[i])
// 	{
// 		if (ft_strncmp(envp[i], "PATH", 4) == 0)
// 			return (envp[i] + 5);
// 		i++;
// 	}
// 	return (NULL);
// }

// char	*get_path2(char **array_argv, char **envp)
// {
// 	char		*paths_string;
// 	char		**paths_array;
// 	int			i;
// 	char		*joined;
// 	char		*path;

// 	paths_string = env_path2(envp);
// 	if (paths_string != NULL)
// 	{
// 		paths_array = ft_split(paths_string, ':');
// 		i = 0;
// 		while (paths_array[i])
// 		{
// 			joined = ft_strjoin(paths_array[i], "/");
// 			path = ft_strjoin(joined, array_argv[0]);
// 			if (access(path, R_OK) == 0)
// 				return (path);
// 			i++;
// 			free(joined);
// 			free(path);
// 		}
// 		free_array(paths_array);
// 	}
// 	return (NULL);
// }

// void	handle_pipe2(char *argv, char **envp, int i)
// {
// 	int		pipefd[2];
// 	char	**parsearg;
// 	char	*path_found;
// 	pid_t	pid1;

// 	pipe(pipefd);
// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		dprintf(2, "[%d]\n", i);
// 		parsearg = ft_split(argv, ' ');
// 		path_found = get_path2(parsearg, envp);
// 		close(pipefd[0]);
// 		dup2(pipefd[1], 1);
// 		execve(path_found, parsearg, envp);
// 		exit(0);
// 	}
// 	// wait(NULL);
// 	close(pipefd[1]);
// 	dup2(pipefd[0], 0);
// 	close(pipefd[0]);
// }

// void	lastexec3(char *string, char **envp)
// {
// 	pid_t	pid1;
// 	char	**parsearg;
// 	char	*path_found;

// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		dprintf(2, "[5]\n");
// 		parsearg = ft_split(string, ' ');
// 		path_found = get_path2(parsearg, envp);
// 		execve(path_found, parsearg, envp);
// 	}
// 	// wait(NULL);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int		fd1;
// 	int		i;

// 	i = 2;
// 	fd1 = open(argv[1], O_RDONLY);
// 	dup2(fd1, 0);
// 	while (i < 6)
// 	{
// 		handle_pipe2(argv[i], envp, i - 1);
// 		i++;
// 	}
// 	lastexec3(argv[argc - 1], envp);
// 	waitpid(-1,NULL,0);
// 	waitpid(-1,NULL,0);
// 	waitpid(-1,NULL,0);
// 	waitpid(-1,NULL,0);
// 	waitpid(-1,NULL,0);
// 	dprintf(2, "[0]\n");
// 	close(fd1);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		i;
// 	int		j;
// 	int		k;

// 	i = 2;
// 	j = 0;
// 	if (argument_number(argc) == 1)
// 		return (1);
// 	if (outfile_rights(argv[argc - 1]) == 1)
// 		j++;
// 	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
// 	{
// 		if (j == 0)
// 			fd2 = open(argv[argc - 1], O_CREAT | O_APPEND | O_WRONLY, 0644);
// 		heredoc(argv[2]);
// 		fd1 = open("temp", O_CREAT | O_RDWR, 0644);
// 		dup2(fd1, 0);
// 		i++;
// 	}
// 	else
// 	{
// 		if (j == 0)
// 			fd2 = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
// 		if (infile_exist(argv[1]) == 1)
// 			i++;
// 		if (i == 2)
// 			fd1 = open(argv[1], O_RDONLY);
// 		else
// 			fd1 = open(argv[1], O_CREAT, 0644);
// 		dup2(fd1, 0);
// 	}
// 	k = i;
// 	while (k < argc - 2)
// 	{
// 		handle_pipe(argv[k], envp);
// 		k++;
// 	}
// 	if (j == 0)
// 	{
// 		dup2(fd2, 1);
// 		lastexec(argv[argc - 2], envp);
// 	}
// 	if (i == 3 && ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) != 0)
// 		unlink(argv[1]);
// 	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
// 		unlink("temp");
// 	if (j == 1)
// 		dprintf(2, "permission denied: %s\n", argv[argc - 1]);
// 	close(fd1);
// 	close(fd2);
// 	return (0);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		i;
// 	int		j;
// 	// char	**env_path;
// 	int		k;

// 	i = 2;
// 	j = 0;
// 	if (argument_number(argc) == 1)
// 		return (1);
// 	if (outfile_rights(argv[argc - 1]) == 1)
// 		j++;
// 	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
// 	{
// 		if (j == 0)
// 			fd2 = open(argv[argc - 1], O_CREAT | O_APPEND | O_WRONLY, 0644);
// 		heredoc(argv[2]);
// 		fd1 = open("temp", O_CREAT | O_RDWR, 0644);
// 		dup2(fd1, 0);
// 		i++;
// 	}
// 	else
// 	{
// 		if (j == 0)
// 			fd2 = open(argv[argc - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
// 		if (infile_exist(argv[1]) == 1)
// 			i++;
// 		if (i == 2)
// 			fd1 = open(argv[1], O_RDONLY);
// 		else
// 			fd1 = open(argv[1], O_CREAT, 0644);
// 		dup2(fd1, 0);
// 	}
// 	k = i;
// 	while (k < argc - 2)
// 	{
// 		handle_pipe(argv[k], envp);
// 		k++;
// 		wait(NULL);
// 	}
// 	if (j == 0)
// 	{
// 		dup2(fd2, 1);
// 		lastexec(argv[argc - 2], envp);
// 		wait(NULL);
// 	}
// 	if (i == 3 && ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) != 0)
// 		unlink(argv[1]);
// 	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
// 		unlink("temp");
// 	if (j == 1)
// 		dprintf(2, "permission denied: %s\n", argv[argc - 1]);
// 	close(fd1);
// 	close(fd2);
// 	// env_path = get_env_path(envp);
// 	return (0);
// }

// void	heredoc(int fd, char *arg)
// {
// 	char	*string;

// 	while (1)
// 	{
// 		string = get_next_line(0);
// 		if (string == NULL || ft_strncmp(string, arg, ft_strlen(arg)) == 0)
// 			break ;
// 		ft_putstr_fd(string, fd);
// 		free(string);
// 	}
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	// int		fd1;
// 	// int		fd2;
// 	// char	*string;

// 	printf("%s\n", argv[0]);
// 	printf("%d\n", argc);
// 	displayarray(envp);
// 	return (0);
// }

// void	lastexec2(char *string, char **envp)
// {
// 	pid_t	pid1;
// 	char	**parsearg;
// 	char	*const args[] = { "ls", NULL};

// 	parsearg = get_single_arg_array(string);
// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{

// 		execve("/usr/bin/ls", args, envp);
// 		exit(0);
// 	}
// 	wait(NULL);
// 	free_array(parsearg, 1);

// 	// parsearg = NULL;
// 	// pid1 = fork();
// 	// if (pid1 == 0)
// 	// {
// 	// 	parsearg = get_single_arg_array(string);
// 	// 	execve("/usr/bin/ls", args, envp);
// 	// 	exit(0);
// 	// }
// 	// wait(NULL);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	int		fd1;
// 	char	**env_path;

// 	fd1 = open(argv[1], O_RDONLY);
// 	env_path = get_env_path(envp);
// 	free_array(env_path, 11);
// 	// // char	*const args[] = { "ls", NULL};
// 	printf("%d\n", argc);
// 	printf("%s", argv[1]);
// 	// lastexec2(argv[1], envp);
// 	// // execve("/usr/bin/ls", args, envp);
// 	// close(fd1);

// }

// int		parse_cmd(char **argv, char ** env_path, int i, int argc)
// {
// 	char		*path_found;
// 	char		**cmd_array;

// 	while (i < argc - 2)
// 	{
// 		cmd_array = get_single_arg_array(argv[i]);
// 		path_found = find_path(env_path, cmd_array[0]);
// 		if (path_found == NULL)
// 		{
// 			dprintf(2,"command not found: %s\n", cmd_array[0]);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// void handle_pipe2(char *argv)
// {
// 	char	*string;
// 	int		pipefd[2];
// 	pid_t	pid1;

// 	pipe(pipefd);
// 	pid1 = fork();
// 	if (pid1 == 0)
// 	{
// 		close(pipefd[0]);
// 		while (1)
// 		{
// 			string = get_next_line(0);
// 			if (ft_strncmp(string, argv, ft_strlen(argv)) == 0)
// 				break ;
// 			ft_putstr_fd(string, pipefd[1]);
// 			free(string);
// 		}
// 		exit(0);
// 	}
// 	// wait(NULL);
// 	close(pipefd[1]);
// 	dup2(pipefd[0], 0);

// }

//////////////////////////// version simplifiee 4 child

	// int		pipefd[2];
	// int		pipefd2[2];
	// int		pipefd3[2];
	// pid_t	pid1;
	// pid_t	pid2;
	// pid_t	pid3;
	// pid_t	pid4;
	// int		fd1;
	// int		fd2;

	// pipe(pipefd);
	// pipe(pipefd2);
	// pipe(pipefd3);
	// fd1 = open(argv[1], O_RDONLY);
	// fd2 = open(argv[6], O_WRONLY);
	// pid1 = fork();
	// if (pid1 == 0)
	// {
	// 	close(pipefd[0]);
	// 	close(pipefd2[0]);
	// 	close(pipefd2[1]);
	// 	close(pipefd3[0]);
	// 	close(pipefd3[1]);
	// 	dup2(fd1, 0);
	// 	dup2(pipefd[1], 1);
	// 	execve("/usr/bin/grep", get_arg(argv[2]), envp);
	// 	exit(0);
	// }
	// pid2 = fork();
	// if (pid2 == 0)
	// {
	// 	close(pipefd[1]);
	// 	close(pipefd2[0]);
	// 	close(pipefd3[0]);
	// 	close(pipefd3[1]);
	// 	dup2(pipefd[0], 0);
	// 	dup2(pipefd2[1], 1);
	// 	execve("/usr/bin/grep", get_arg(argv[3]), envp);
	// 	exit(0);
	// }

	// pid4 = fork();
	// if (pid4 == 0)
	// {
	// 	close(pipefd2[1]);
	// 	close(pipefd3[0]);
	// 	close(pipefd[0]);
	// 	close(pipefd[1]);
	// 	dup2(pipefd2[0], 0);
	// 	dup2(pipefd3[1], 1);
	// 	execve("/usr/bin/grep", get_arg(argv[4]), envp);
	// 	exit(0);
	// }

	// pid3 = fork();
	// if (pid3 == 0)
	// {
	// 	close(pipefd3[1]);
	// 	close(pipefd[0]);
	// 	close(pipefd[1]);
	// 	close(pipefd2[0]);
	// 	close(pipefd2[1]);
	// 	dup2(pipefd3[0], 0);
	// 	dup2(fd2, 1);
	// 	execve("/usr/bin/wc", get_arg(argv[5]), envp);
	// 	exit(0);
	// }
	// close(pipefd[0]);
	// close(pipefd[1]);
	// close(pipefd2[0]);
	// close(pipefd2[1]);
	// close(pipefd3[0]);
	// close(pipefd3[1]);
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
	// waitpid(pid3, NULL, 0);
	// waitpid(pid4, NULL, 0);
	// return (0);

//////////////////////////////////////// VERSION SIMPLIFIEE

	// int		pipefd[2];
	// pid_t	pid1;
	// pid_t	pid2;
	// int		fd1;
	// int		fd2;

	// pipe(pipefd);
	// fd1 = open(argv[1], O_RDONLY);
	// fd2 = open(argv[4], O_WRONLY);
	// pid1 = fork();
	// if (pid1 == 0)
	// {
	// 	close(pipefd[0]);
	// 	dup2(fd1, 0);
	// 	dup2(pipefd[1], 1);
	// 	execve("/usr/bin/grep", get_arg(argv[2]), envp);
	// 	exit(0);
	// }
	// pid2 = fork();
	// if (pid2 == 0)
	// {
	// 	close(pipefd[1]);
	// 	dup2(pipefd[0], 0);
	// 	dup2(fd2, 1);
	// 	execve("/usr/bin/wc", get_arg(argv[3]), envp);
	// 	exit(0);
	// }
	// // close(pipefd[0]);
	// // close(pipefd[1]);
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
	// return (0);

//////////////////////////////////////// VERSION ORIGINALE 2 CHILD

	// int		pipefd[2];
	// pid_t	pid1;
	// pid_t	pid2;
	// int		fd1;
	// int		fd2;

	// if (argument_number(argc) == 1)
	// 	return (1);
	// if (infile_exist(argv[1]) == 1)
	// 	return (1);
	// if (outfile_rights(argv[4]) == 1)
	// 	return (1);
	// if (pipe(pipefd) == -1)
	// 	return (1);
	// fd1 = open(argv[1], O_RDONLY);
	// fd2 = open(argv[4], O_WRONLY);
	// pid1 = fork();
	// if (pid1 == -1)
	// 	return (1);
	// if (pid1 == 0)
	// 	child(argv[2], fd1, pipefd[1], pipefd[0], envp);
	// pid2 = fork();
	// if (pid2 == -1)
	// 	return (1);
	// if (pid2 == 0)
	// 	child(argv[3], pipefd[0], fd2, pipefd[1], envp);
	// close(pipefd[0]);
	// close(pipefd[1]);
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
	// close(fd1);
	// close(fd2);
	// return (0);

//////////////////////////////////////// VERSION SIMPLIFIEE - PIPE

	// // int		pipefd[2];
	// pid_t	pid1;
	// pid_t	pid2;
	// int		fd1;
	// int		fd2;
	// char	*const args[] = { "ls", NULL};
	// // pipe(pipefd);
	// fd1 = open(argv[1], O_RDONLY);
	// fd2 = open(argv[4], O_WRONLY);
	// pid1 = fork();
	// if (pid1 == 0)
	// {
	// 	// close(pipefd[0]);
	// 	// dup2(fd1, 0);
	// 	// dup2(pipefd[1], 1);
	// 	// execve("/usr/bin/grep", get_arg(argv[2]), envp);
	// 	execve("/usr/bin/ls", args, envp);
	// 	exit(0);
	// }
	// pid2 = fork();
	// if (pid2 == 0)
	// {
	// 	// close(pipefd[1]);
	// 	// dup2(pipefd[0], 0);
	// 	// dup2(fd2, 1);
	// 	// execve("/usr/bin/wc", get_arg(argv[3]), envp);
	// 	execve("/usr/bin/ls", args, envp);
	// 	exit(0);
	// }
	// // close(pipefd[0]);
	// // close(pipefd[1]);
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
	// return (0);

//////////////////////////////////////// VERSION SIMPLIFIEE - EXECVE

	// int		pipefd[2];
	// pid_t	pid1;
	// pid_t	pid2;
	// int		fd1;
	// int		fd2;
	// 	char	*buffer2;
	// buffer2 = (char *)malloc(sizeof(char) * (1000 + 1));

	// pipe(pipefd);
	// fd1 = open(argv[1], O_RDONLY);
	// fd2 = open(argv[4], O_WRONLY);
	// pid1 = fork();
	// if (pid1 == 0)
	// {
	// 	close(pipefd[0]);
	// 	dup2(fd1, 0);
	// 	dup2(pipefd[1], 1);
	// 	// execve("/usr/bin/grep", get_arg(argv[2]), envp);
	// 	write(pipefd[1], argv[1], strlen(argv[1]));
	// 	exit(0);
	// }
	// pid2 = fork();
	// if (pid2 == 0)
	// {
	// 	close(pipefd[1]);
	// 	dup2(pipefd[0], 0);
	// 	dup2(fd2, 1);
	// 	// execve("/usr/bin/wc", get_arg(argv[3]), envp);
	// while (read(pipefd[0], buffer2, 1) > 0)
	// 	write(STDOUT_FILENO, buffer2, 1);
	// write(STDOUT_FILENO, "\n", 1);
	// 	exit(0);
	// }
	// // close(pipefd[0]);
	// // close(pipefd[1]);
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
	// return (0);

//////////////////////////////////////// VERSION PLEIN DE TESTS

	// 	int		pipefd[2];
	// pid_t	pid1;
	// pid_t	pid2;
	// int		fd1;
	// int		fd2;

	// int		readvalue1;
	// char	*buffer1;
	// buffer1 = (char *)malloc(sizeof(char) * (1000 + 1));
	// int		readvalue2;
	// char	*buffer2;
	// buffer2 = (char *)malloc(sizeof(char) * (1000 + 1));
	// pipe(pipefd);
	// fd1 = open(argv[1], O_RDONLY);
	// fd2 = open(argv[4], O_WRONLY);
	// pid1 = fork();
	// if (pid1 == 0)
	// {
	// 	close(pipefd[0]);
	// 	dup2(fd1, 0);
	// 	dup2(pipefd[1], 1);
	// 	// dprintf(2, "3\n");
	// 	// readvalue2 = read(fd1, buffer2, 1000);
	// 	// printf("%s\n", buffer2);
	// 	printf("hello\n");
	// 	// execve("/usr/bin/grep", get_arg(argv[2]), envp);
	// 	// execve("/usr/bin/ls", get_arg(argv[2]), envp);
	// 	exit(0);
	// }
	// pid2 = fork();
	// if (pid2 == 0)
	// {
	// 	close(pipefd[1]);
	// 	dup2(pipefd[0], 0);
	// 	dup2(fd2, 1);
	// 	// dprintf(2, "4\n");
	// 	// readvalue1 = read(pipefd[0], buffer1, 1000);
	// 	// write(1, buffer1, 1000);
		// while (read(pipefd[0], buffer2, 1) > 0)
		// 	write(STDOUT_FILENO, buffer2, 1);
		// write(STDOUT_FILENO, "\n", 1);
	// 	// execve("/usr/bin/ls", get_arg(argv[3]), envp);
	// 	// execve("/usr/bin/wc", get_arg(argv[3]), envp);
	// 	exit(0);
	// }
	// // dprintf(2, "1\n");
	// close(pipefd[0]);
	// // close(pipefd[1]);
	// // dprintf(2, "2\n");
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
	// // dprintf(2, "5\n");
	// return (0);

//////////////////////////////////////// VERSION IMBRIQUEE

// 	int		pipefd[2];
// 	int		fd1;
// 	int		fd2;
// 	pid_t child1;
//     pid_t child2;
// 	pipe(pipefd);
// 	fd1 = open(argv[1], O_RDONLY);
// 	fd2 = open(argv[4], O_WRONLY);
//     child1 = fork();

// if (child1 == 0) {
//     close(pipefd[0]);
// 		dup2(fd1, 0);
// 		dup2(pipefd[1], 1);
// 		execve("/usr/bin/grep", get_arg(argv[2]), envp);
// 		exit(0);
// } else {
//     child2 = fork();

//     if (child2 == 0) {
//         close(pipefd[1]);
// 		dup2(pipefd[0], 0);
// 		dup2(fd2, 1);
// 		execve("/usr/bin/wc", get_arg(argv[3]), envp);
// 		exit(0);
//     } else {
// 			close(pipefd[0]);
// 	// close(pipefd[1]);
//         waitpid(child1, NULL, 0);
// 	waitpid(child2, NULL, 0);
// 	return (0);
//     }
// }

//////////////////////////////////////// VERSION 1 CHILD

	// int pipefd[2];
	// pid_t cpid;
	// char buf;

	// pipe(pipefd);
	// cpid = fork();
	// if (cpid == 0) {    /* Le fils lit dans le tube */
	// 	close(pipefd[1]);
	// 	while (read(pipefd[0], &buf, 1) > 0)
	// 		write(STDOUT_FILENO, &buf, 1);
	// 	write(STDOUT_FILENO, "\n", 1);
	// 	close(pipefd[0]);
	// 	_exit(EXIT_SUCCESS);
	// } else {            /* Le père écrit argv[1] dans le tube */
	// 	close(pipefd[0]);
	// 	write(pipefd[1], "salut", 5);
	// 	// close(pipefd[1]);          /* Le lecteur verra EOF */
	// 	wait(NULL);                /* Attente du fils */
	// 	exit(EXIT_SUCCESS);
	// }

//////////////////////////////////////// VERSION SIMPLIFEE REMIX 1 CHILD

	// int pipefd[2];
	// pid_t cpid;
	// char buf;
	// pid_t	pid2;

	// pipe(pipefd);
	// cpid = fork();
	// if (cpid == 0)
	// {
	// 	close(pipefd[0]);
	// 	write(pipefd[1], "salut", 5);
	// 	_exit(EXIT_SUCCESS);
	// }
	// else
	// {
	// 	pid2 = fork();
	// 	if (pid2 == 0)
	// 	{
	// 		close(pipefd[1]); 
	// 		while (read(pipefd[0], &buf, 1) > 0)
	// 			write(STDOUT_FILENO, &buf, 1);
	// 		write(STDOUT_FILENO, "\n", 1);
	// 		close(pipefd[0]);
	// 		_exit(EXIT_SUCCESS);
	// 	}
	// 	else
	// 	{
	// 		close(pipefd[0]);
	// 		// close(pipefd[1]);
	// 		wait(NULL);
	// 		wait(NULL);
	// 		exit(EXIT_SUCCESS);
	// 	}
	// }

	// int		pipefd[2];
	// pid_t	pid1;
	// pid_t	pid2;
	// char	*buffer2;

	// buffer2 = (char *)malloc(sizeof(char) * (10 + 1));
	// pipe(pipefd);
	// pid1 = fork();
	// if (pid1 == 0)
	// {
	// 	close(pipefd[0]);
	// 	write(pipefd[1], "salut\n", 6);
	// 	exit(0);
	// }
	// pid2 = fork();
	// if (pid2 == 0)
	// {
	// 	close(pipefd[1]);
	// 	// read(pipefd[0], buffer2, 10);
	// 	// write(1, buffer2, 6);
	// 	while (read(pipefd[0], buffer2, 1) > 0)
	// 		write(STDOUT_FILENO, buffer2, 1);
	// 	write(STDOUT_FILENO, "\n", 1);
	// 	exit(0);
	// }
	// close(pipefd[0]);
	// // close(pipefd[1]);
	// waitpid(pid1, NULL, 0);
	// waitpid(pid2, NULL, 0);
	// return (0);
