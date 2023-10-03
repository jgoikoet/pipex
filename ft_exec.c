/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:04:40 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/16 20:15:19 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipe_child2(t_data *d, int *fd, int id)
{
	int	fd2;

	wait(NULL);
	close(fd[1]);
	id = fork();
	if (id == -1)
		return (write(1, "Error occured whith fork\n", 25), -1);
	if (id == 0)
	{
		fd2 = open(d->a2, O_TRUNC | O_WRONLY);
		if (fd2 == -1)
			return (write(1, "Can not open file\n", 18), -1);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			return (write(1, "Error occured whith dup2\n", 18), -1);
		close (fd[0]);
		if (dup2(fd2, STDOUT_FILENO) == -1)
			return (write(1, "Error occured whith dup2\n", 18), -1);
		execve(d->p2, d->c2, NULL);
	}
	else
		close(fd[0]);
	return (0);
}

int	ft_pipe_exec(t_data *d)
{
	int	fd[2];
	int	fd2;
	int	id;

	if (pipe(fd) == -1)
		return (write(1, "Error creating pipe\n", 20), -1);
	id = fork();
	if (id == -1)
		return (write(1, "Error occured whith fork\n", 25), -1);
	if (id == 0)
	{
		fd2 = open(d->a1, O_RDONLY);
		if (fd2 == -1)
			return (write(1, "Can not open file\n", 18), -1);
		if (dup2(fd2, STDIN_FILENO) == -1)
			return (write(1, "Error occured whith dup2\n", 18), -1);
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			return (write(1, "Error occured whith dup2\n", 18), -1);
		close(fd[1]);
		execve(d->p1, d->c1, NULL);
	}
	else
		ft_pipe_child2(d, fd, id);
	return (0);
}

void	set_path(t_data *d)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	while (d->path[i])
	{
		str1 = ft_strjoin(d->path[i++], "/", 0);
		str2 = ft_strjoin(str1, d->c1[0], 1);
		if (!access(str2, F_OK))
			d->p1 = str2;
		else
			free(str2);
	}
	i = 0;
	while (d->path[i])
	{
		str1 = ft_strjoin(d->path[i++], "/", 0);
		str2 = ft_strjoin(str1, d->c2[0], 1);
		if (!access(str2, F_OK))
			d->p2 = str2;
		else
			free(str2);
	}
}

void	ft_exec(char **env, t_data *d)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_check_path(env[i]))
			d->path = ft_split(env[i] + 5, ':');
		i++;
	}
	set_path(d);
	ft_free(d->path);
	ft_pipe_exec(d);
	free(d->p1);
	free(d->p2);
}
