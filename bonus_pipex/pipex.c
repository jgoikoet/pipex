/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:13:41 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/16 20:01:55 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		free(ar[i++]);
	free(ar);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin_pip(char *s1, char *s2, int f)
{
	char	*res;
	int		i;
	int		size;

	if (!s1 || !s2)
		return (0);
	i = 0;
	size = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	res = (char *) malloc (sizeof(char) * (size + 1));
	if (res == NULL)
		return (0);
	i = 0;
	size = 0;
	while (s1[i] != '\0')
		res[size++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		res[size++] = s2[i++];
	res[size] = '\0';
	if (f)
		free (s1);
	return (res);
}

int	ft_check_path(char *s)
{
	if (s[0] == 'P' && s[1] == 'A' && s[2] == 'T' && s[3] == 'H')
		return (1);
	return (0);
}

int	main(int argc, char	**argv, char **env)
{
	char	**c;
	int		i;

	if (argc < 5)
		return (write(1, "Error\nIncorrect number of arguments.\n", 37), 1);
	if (!ft_strcmp("here_doc", argv[1]))
		ft_exec_here_doc(argc, argv, env);
	else
	{
		if (ft_error_file(argc, argv, 1))
			return (0);
		i = 2;
		while (i < argc - 1)
		{
			c = ft_split(argv[i++], ' ');
			if (ft_error_command(env, c[0]))
				return (ft_free(c), write(1, "Error\nInvalid command\n", 24), 1);
			ft_free(c);
		}
		ft_exec(argc, argv, env);
	}
	return (0);
}
