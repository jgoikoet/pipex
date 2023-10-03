/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:26:25 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/06/16 13:47:24 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_savst(char *str, int i)
{
	static char	*sstr = NULL;

	if (i == 1)
	{
		free (sstr);
		sstr = NULL;
	}
	if (str)
		sstr = str;
	return (sstr);
}

int	ft_clear(void)
{
	char	*str;
	int		i;
	int		j;

	if (!ft_check_jump())
		return (free(ft_savst(0, 1)), 0);
	i = 0;
	while (ft_savst(0, 0)[i] != '\n' && ft_savst(0, 0)[i] != '\0')
		i++;
	if (ft_savst(0, 0)[++i] == '\0')
		return (free(ft_savst(0, 1)), 0);
	j = i;
	while (ft_savst(0, 0)[i] != '\0')
		i++;
	str = (char *) malloc (sizeof(char) * (i - j) + 1);
	i = j;
	j = 0;
	while (ft_savst(0, 0)[i] != '\0')
		str[j++] = ft_savst(0, 0)[i++];
	str[j] = '\0';
	ft_savst(0, 1);
	ft_savst(str, 0);
	return (0);
}
