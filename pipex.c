/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:13:41 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/13 17:46:30 by jgoikoet         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2, int f)
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
	t_data	*d;

	if (argc != 5)
		return (write(1, "Error\nIncorrect number of arguments.\n", 37), 1);
	if (ft_error_file(argv))
		return (0);
	d = (t_data *) malloc (sizeof(t_data));
	if (!d)
		return (write(1, "Error\n", 6), 0);
	d->c1 = ft_split(argv[2], ' ');
	d->c2 = ft_split(argv[3], ' ');
	if (ft_error_command(env, d->c1[0]) || ft_error_command(env, d->c2[0]))
	{
		ft_free (d->c1);
		ft_free (d->c2);
		free (d);
		return (write(1, "Error\nOne or both commands incorrect\n", 37), 1);
	}
	d->a1 = argv[1];
	d->a2 = argv[4];
	ft_exec(env, d);
	return (ft_free(d->c1), ft_free(d->c2), free (d), 0);
}
