/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:19:48 by keguchi           #+#    #+#             */
/*   Updated: 2021/06/09 22:19:51 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirect_file(int argc, char **argv)
{
	int	input_fd;
	int	output_fd;

	input_fd = 0;
	output_fd = 0;
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd < 0)
	{
		perror("open");
		close(input_fd);
		return (OPEN_ERROR);
	}
	output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT, 0666);
	if (output_fd < 0)
	{
		perror("open");
		close(input_fd);
		return (OPEN_ERROR);
	}
	dup2(input_fd, STDIN_FILENO);
	close(input_fd);
	dup2(output_fd, STDOUT_FILENO);
	close(output_fd);
	return (0);
}

int	init_cmd(t_cmd *cmds, char *str)
{
	cmds->cmd = ft_split(str, ' ');
	cmds->cmd_path[0] = ft_strjoin("/bin/", str);
	cmds->cmd_path[1] = ft_strjoin("/sbin/", str);
	cmds->cmd_path[2] = ft_strjoin("/usr/bin/", str);
	cmds->cmd_path[3] = ft_strjoin("/usr/sbin/", str);
	cmds->cmd_path[4] = ft_strjoin("/usr/local/bin/", str);
	cmds->cmd_path[5] = ft_strjoin("/usr/local/sbin/", str);
	if (!cmds->cmd || !cmds->cmd_path[0] || !cmds->cmd_path[1]
		|| !cmds->cmd_path[2] || !cmds->cmd_path[3]
		|| !cmds->cmd_path[4] || !cmds->cmd_path[5])
	{
		perror("malloc");
		return (MALLOC_ERROR);
	}
	return (0);
}

void	pipex(t_cmd *cmd, char **argv, int pid, int *pipe_fd)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	if (pid == 0)
	{
		status = init_cmd(cmd, argv[CMD_1]);
		close(pipe_fd[READ_FD]);
		dup2(pipe_fd[WRITE_FD], STDOUT_FILENO);
		close(pipe_fd[WRITE_FD]);
	}
	else
	{
		status = init_cmd(cmd, argv[CMD_2]);
		close(pipe_fd[WRITE_FD]);
		dup2(pipe_fd[READ_FD], STDIN_FILENO);
		close(pipe_fd[READ_FD]);
	}
	if (status == MALLOC_ERROR)
		exit(EXIT_FAILURE);
	while (i < 6)
		execve(cmd->cmd_path[i++], cmd->cmd, NULL);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	t_cmd	cmd;
	int		status;
	int		pipe_fd[2];
	int		i;

	i = 0;
	status = redirect_file(argc, argv);
	if (status == OPEN_ERROR)
		exit(EXIT_FAILURE);
	pipe(pipe_fd);
	pid = fork();
	if (pid < 0)
		return (0);
	else if (pid == 0)
		pipex(&cmd, argv, pid, pipe_fd);
	else
	{
		wait(&status);
		pipex(&cmd, argv, pid, pipe_fd);
	}
	exit(EXIT_SUCCESS);
}
