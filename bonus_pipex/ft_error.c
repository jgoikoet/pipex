/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:01:10 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/15 18:07:12 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error_file(int argc, char **argv, int i)
{
	if (access(argv[1], F_OK) && i)
		return (write(1, "Error\nFile.1 does not exist\n", 28), 1);
	else if (access(argv[1], R_OK) && i)
		return (write(1, "Error\nFile.1 no read permissions\n", 33), 2);
	else if (access(argv[argc - 1], F_OK))
		return (write(1, "Error\nFile.2 does not exist\n", 28), 1);
	else if (access(argv[argc -1], W_OK))
		return (write(1, "Error\nFile.2 no write permissions\n", 34), 2);
	return (0);
}

int	ft_error_command(char **env, char *s)
{
	int		i;
	char	**dirs;
	char	*str1;
	char	*str2;
	int		check;

	check = 1;
	i = 0;
	while (env[i])
	{
		if (ft_check_path(env[i]))
			dirs = ft_split(env[i] + 5, ':');
		i++;
	}
	i = 0;
	while (dirs[i])
	{
		str1 = ft_strjoin_pip(dirs[i++], "/", 0);
		str2 = ft_strjoin_pip(str1, s, 1);
		if (!access(str2, F_OK))
			check = 0;
		free(str2);
	}
	return (ft_free(dirs), check);
}
