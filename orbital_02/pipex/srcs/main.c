/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frangome <frangome@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:31:36 by frangome          #+#    #+#             */
/*   Updated: 2023/09/04 15:31:57 by frangome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_charchar(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = get_path(s_cmd[0], env);
	if (execve(path, s_cmd, env) == -1)
		free_charchar(s_cmd);
}

int	child(char **argv, char **env, int *p_fd)
{
	int	fd1;

	fd1 = open(argv[1], O_RDONLY, 0777);
	if (!fd1)
		return (0);
	dup2(fd1, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	exec(argv[2], env);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;
	int		fd2;

	if (argc != 5)
		return (0);
	if (pipe(p_fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (!pid)
		if (!child(argv, env, p_fd))
			return (0);
	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (!fd2)
		return (0);
	dup2(fd2, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	exec(argv[3], env);
	return (0);
}
