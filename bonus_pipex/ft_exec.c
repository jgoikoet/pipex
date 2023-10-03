/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:04:40 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/18 11:19:52 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipe_last(t_data *d)
{
	d->com = ft_split(d->argv[d->argc - 2], ' ');
	d->pat = set_path(d, d->com[0]);
	close(d->fda[1]);
	d->id = fork();
	if (d->id == -1)
		return (write(1, "Error occured whith fork\n", 25), -1);
	if (d->id == 0)
	{
		if (d->com_1 == 2)
			d->fd2 = open(d->a2, O_TRUNC | O_WRONLY);
		else
			d->fd2 = open(d->a2, O_APPEND | O_WRONLY);
		if (d->fd2 == -1)
			return (write(1, "Can not open file\n", 18), -1);
		if (dup2(d->fda[0], STDIN_FILENO) == -1)
			return (write(1, "Error occured whith dup2\n", 18), -1);
		close (d->fda[0]);
		if (dup2(d->fd2, STDOUT_FILENO) == -1)
			return (write(1, "Error occured whith dup2\n", 18), -1);
		execve(d->pat, d->com, NULL);
	}
	return (ft_free(d->com), free(d->pat), close(d->fda[0]), 0);
}

int	ft_mid_exect(t_data *d)
{
	if (dup2(d->fda[0], STDIN_FILENO) == -1)
		return (write(1, "Error occured whith dup2\n", 25), -1);
	close (d->fda[0]);
	if (dup2(d->fdb[1], STDOUT_FILENO) == -1)
		return (write(1, "Error occured whith dup2\n", 25), -1);
	close (d->fdb[1]);
	execve(d->pat, d->com, NULL);
	return (0);
}

int	ft_pipe_mid(t_data *d)
{
	int	i;

	ft_free(d->com);
	free(d->pat);
	i = d->mid_i;
	while (d->mid_i < d->argc - 2)
	{
		close(d->fda[1]);
		pipe(d->fdb);
		d->id = fork();
		d->com = ft_split(d->argv[d->mid_i], ' ');
		d->pat = set_path(d, d->com[0]);
		wait(NULL);
		if (d->id == 0)
			ft_mid_exect(d);
		ft_free(d->com);
		free(d->pat);
		close(d->fda[0]);
		close(d->fdb[1]);
		d->fda[0] = d->fdb[0];
		d->fda[1] = d->fdb[1];
		d->mid_i++;
		i++;
	}
	return (ft_pipe_last(d), 0);
}

int	ft_pipe_exec(t_data *d)
{
	d->com = ft_split(d->argv[d->com_1], ' ');
	d->pat = set_path(d, d->com[0]);
	if (pipe(d->fda) == -1)
		return (write(1, "Error creating pipe\n", 20), -1);
	d->id = fork();
	if (d->id == -1)
		return (write(1, "Error occured whith fork\n", 25), -1);
	if (d->id == 0)
	{
		d->fd2 = open(d->a1, O_RDONLY);
		if (d->fd2 == -1)
			return (write(1, "Can not open file\n", 18), -1);
		if (dup2(d->fd2, STDIN_FILENO) == -1)
			return (write(1, "Error occured whith dup2\n", 25), -1);
		close(d->fda[0]);
		if (dup2(d->fda[1], STDOUT_FILENO) == -1)
			return (write(1, "Error occured whith dup2\n", 25), -1);
		close(d->fda[1]);
		execve(d->pat, d->com, NULL);
	}
	else
		ft_pipe_mid(d);
	return (0);
}

int	ft_exec(int argc, char	**argv, char **env)
{
	t_data	*d;
	int		i;

	d = (t_data *) malloc (sizeof(t_data));
	if (!d)
		return (write(1, "Error\n", 6), 0);
	i = 0;
	while (env[i])
	{
		if (ft_check_path(env[i]))
			d->path = ft_split(env[i] + 5, ':');
		i++;
	}
	d->argc = argc;
	d->argv = argv;
	d->a1 = argv[1];
	d->a2 = argv[argc - 1];
	d->mid_i = 3;
	d->com_1 = 2;
	ft_pipe_exec(d);
	ft_free(d->path);
	free (d);
	return (0);
}
