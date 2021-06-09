/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keguchi <keguchi@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:20:54 by keguchi           #+#    #+#             */
/*   Updated: 2021/06/09 22:20:56 by keguchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

/*
******** define ***********************************************
*/

# define READ_FD		0
# define WRITE_FD		1

# define FILE_1			1
# define CMD_1			2
# define CMD_2			3
# define FILE_2			4

# define MALLOC_ERROR	10
# define OPEN_ERROR		11

/*
******** struct ************************************************
*/

typedef struct s_cmd
{
	char	*cmd_path[6];
	char	**cmd;
}				t_cmd;

/*
******** pipex **************************************************
*/

int		main(int argc, char *argv[]);
void	pipex(t_cmd *cmd, char **argv, int pid, int *pipe_fd);
int		init_cmd(t_cmd *cmds, char *str);
int		redirect_file(int argc, char **argv);

#endif
