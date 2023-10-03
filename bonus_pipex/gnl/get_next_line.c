/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:24:12 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/06/19 12:44:09 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_final(void)
{
	int		i;
	char	*final;

	i = 0;
	while (ft_savst(0, 0)[i] != '\n' && ft_savst(0, 0)[i] != '\0')
		i++;
	final = (char *) malloc (sizeof(char) * i + 2);
	if (!final)
		return (0);
	i = 0;
	while (ft_savst(0, 0)[i] != '\n' && ft_savst(0, 0)[i] != '\0')
	{
		final[i] = ft_savst(0, 0)[i];
		i++;
	}
	if (ft_savst(0, 0)[i] == '\n')
		final[i++] = '\n';
	final[i] = '\0';
	ft_clear();
	return (final);
}

int	ft_check_jump(void)
{
	int	i;
	int	ok;

	i = 0;
	ok = 0;
	if (!ft_savst(0, 0))
		return (0);
	while (ft_savst(0, 0)[i] != '\0')
	{
		if (ft_savst(0, 0)[i] == '\n')
			ok = 1;
		i++;
	}
	return (ok);
}

int	ft_strjoin(int fd)
{
	char	*temp;
	char	*s;
	int		i;
	int		j;

	while (!ft_check_jump())
	{
		i = 0;
		j = 0;
		temp = ft_read(fd);
		if (!temp)
			return (0);
		s = malloc (sizeof(char) * (ft_len(ft_savst(0, 0))) + ft_len(temp) + 1);
		while (ft_savst(0, 0) && ft_savst(0, 0)[i] != '\0')
			s[j++] = ft_savst(0, 0)[i++];
		i = 0;
		while (temp[i] != '\0')
			s[j++] = temp[i++];
		s[j] = '\0';
		free (temp);
		ft_savst(0, 1);
		ft_savst(s, 0);
	}
	return (1);
}

char	*ft_read(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		bytesreaded;
	char	*str;
	int		i;

	str = NULL;
	i = -1;
	bytesreaded = read (fd, buffer, BUFFER_SIZE);
	if (bytesreaded == 0)
		return (NULL);
	if (bytesreaded == -1)
		return (ft_savst(0, 1), NULL);
	str = (char *) malloc (sizeof (char) * bytesreaded + 1);
	while (++i < bytesreaded)
		str[i] = buffer[i];
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	*res;

	res = NULL;
	if ((!ft_strjoin(fd) && !ft_savst(0, 0)))
		return (NULL);
	res = ft_final();
	return (res);
}
/* int	main(void)
{
	int		fd;

	fd = open("read_error.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	printf("\nfd 1 = %i\n", fd);
	printf(" Linea  1: %s", get_next_line(fd));
	printf(" Linea  2: %s", get_next_line(fd));
	printf(" Linea  3: %s", get_next_line(9));
	// printf(" Linea  4: %s", get_next_line(fd));
	//printf(" Linea  5: %s", get_next_line(fd));
	printf("\n"); 
	close(fd);
	fd = open("read_error.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	printf("\n--------fd 2 = %i-----------\n\n", fd);
	printf(" Linea  1: %s", get_next_line(fd));
	printf(" Linea  2: %s", get_next_line(fd));
	printf(" Linea  3: %s", get_next_line(fd));
	printf(" Linea  4: %s", get_next_line(fd));
	printf(" Linea  5: %s", get_next_line(fd));
	printf("\n");
	close(fd);
	return (0);
} */

/* int	main(void)
{
	int		fd;

	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
	{
		perror("Error al abrir el archivo");
		return (1);
	}
	printf(" Linea  1: %s", get_next_line(fd));
	printf(" Linea  2: %s", get_next_line(fd));
	printf(" Linea  3: %s", get_next_line(fd));
	printf(" Linea  4: %s", get_next_line(fd));
	printf(" Linea  5: %s", get_next_line(fd));
	printf(" Linea  6: %s", get_next_line(fd));
	printf(" Linea  7: %s", get_next_line(fd));
	printf(" Linea  8: %s", get_next_line(fd));
	printf(" Linea  9: %s", get_next_line(fd));
	printf(" Linea 10: %s", get_next_line(fd));
	printf(" Linea 11: %s", get_next_line(fd));
	printf(" Linea 12: %s", get_next_line(fd));
	printf(" Linea 13: %s", get_next_line(fd));
	printf(" Linea 14: %s", get_next_line(fd));
	printf(" Linea 15: %s", get_next_line(fd));
	printf(" Linea 16: %s", get_next_line(fd));
	printf(" Linea 17: %s", get_next_line(fd));
	printf(" Linea 18: %s", get_next_line(fd));
	printf(" Linea 19: %s", get_next_line(fd));
	printf(" Linea 20: %s", get_next_line(fd));
	//printf("\n")
	close(fd);
	return (0);
} */
