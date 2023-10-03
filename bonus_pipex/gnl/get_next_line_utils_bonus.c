/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:26:25 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/05/25 14:54:20 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_le(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_s(char *str, int i, int fd)
{
	static char	*sstr[4096];

	if (i == 1)
	{
		free (sstr[fd]);
		sstr[fd] = NULL;
	}
	if (str)
		sstr[fd] = str;
	return (sstr[fd]);
}

int	ft_clear_b(int fd)
{
	char	*str;
	int		i;
	int		j;

	if (!ft_check_jump_b(fd))
		return (free(ft_s(0, 1, fd)), 0);
	i = 0;
	while (ft_s(0, 0, fd)[i] != '\n' && ft_s(0, 0, fd)[i] != '\0')
		i++;
	if (ft_s(0, 0, fd)[++i] == '\0')
		return (free(ft_s(0, 1, fd)), 0);
	j = i;
	while (ft_s(0, 0, fd)[i] != '\0')
		i++;
	str = (char *) malloc (sizeof(char) * (i - j) + 1);
	i = j;
	j = 0;
	while (ft_s(0, 0, fd)[i] != '\0')
		str[j++] = ft_s(0, 0, fd)[i++];
	str[j] = '\0';
	ft_s(0, 1, fd);
	ft_s(str, 0, fd);
	return (0);
}
