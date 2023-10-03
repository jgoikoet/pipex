/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_here_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:26:43 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/18 11:19:47 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*set_path(t_data *d, char *com)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	while (d->path[i])
	{
		str1 = ft_strjoin_pip(d->path[i++], "/", 0);
		str2 = ft_strjoin_pip(str1, com, 1);
		if (!access(str2, F_OK))
			break ;
		else
			free(str2);
	}
	return (str2);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] == '\n' && s2[i] == '\0')
			return (0);
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

int	ft_temp_set(t_data *d)
{
	int		fd;
	char	*str;

	fd = open ("temp", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	str = get_next_line(0);
	while (ft_strncmp(str, d->here))
	{
		write(fd, str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	free(str);
	return (0);
}

int	ft_here_set(int argc, char	**argv, char **env)
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
	d->a1 = "temp";
	d->a2 = argv[argc - 1];
	d->mid_i = 4;
	d->com_1 = 3;
	d->here = argv[2];
	ft_temp_set(d);
	ft_pipe_exec(d);
	ft_free(d->path);
	unlink("temp");
	return (free (d), 0);
}

int	ft_exec_here_doc(int argc, char	**argv, char **env)
{
	char	**c;
	int		i;

	if (argc < 6)
		return (write(1, "Error\nIncorrect number of arguments.\n", 37), 1);
	if (ft_error_file(argc, argv, 0))
		return (0);
	i = 3;
	while (i < argc - 1)
	{
		c = ft_split(argv[i++], ' ');
		if (ft_error_command(env, c[0]))
			return (ft_free(c), write(1, "Error\nIncorrect command\n", 24), 1);
		ft_free(c);
	}
	ft_here_set(argc, argv, env);
	return (0);
}
