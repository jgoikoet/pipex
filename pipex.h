/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:35:37 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/13 18:03:47 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct data
{
	char	*a1;
	char	*a2;
	char	**c1;
	char	**c2;
	char	**path;
	char	*p1;
	char	*p2;
}				t_data;

/*PIPEX*/
int		main(int argc, char	**argv, char **env);
int		ft_check_path(char *s);
char	*ft_strjoin(char *s1, char *s2, int i);
void	ft_free(char **ar);

/*SPLIT*/
char	**ft_split(char const *s, char c);
int		ft_strcount(const char *s, char c);
char	*ft_subsplit(char const *s, char c, int i);
void	*ft_del(char **array, int j);
size_t	ft_strlen(const char *s);

/*EXEC*/
void	ft_exec(char **env, t_data *d);
void	set_path(t_data *d);
int		ft_pipe_exec(t_data *d);
int		ft_pipe_child2(t_data *d, int *fd, int id);

/*ERROR*/
int		ft_error_command(char **env, char *s);
int		ft_error_file(char	**argv);

#endif