/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 19:35:37 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/09/16 20:08:50 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct data
{
	int		mid_i;
	int		com_1;
	int		argc;
	char	**argv;
	int		fda[2];
	int		fdb[2];
	int		fd2;
	int		id;
	char	*a1;
	char	*a2;
	char	**com;
	char	**path;
	char	*pat;
	char	*here;
}				t_data;

/*PIPEX*/
int		main(int argc, char	**argv, char **env);
int		ft_check_path(char *s);
char	*ft_strjoin_pip(char *s1, char *s2, int i);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_free(char **ar);

/*SPLIT*/
char	**ft_split(char const *s, char c);
int		ft_strcount(const char *s, char c);
char	*ft_subsplit(char const *s, char c, int i);
void	*ft_del(char **array, int j);
size_t	ft_strlen(const char *s);

/*EXEC*/
int		ft_exec(int argc, char	**argv, char **env);
char	*set_path(t_data *d, char *com);
int		ft_pipe_exec(t_data *d);
int		ft_pipe_mid(t_data *d);
int		ft_mid_exect(t_data *d);
int		ft_pipe_last(t_data *d);

/*EXEC_HERE_DOC*/
int		ft_exec_here_doc(int argc, char	**argv, char **env);
int		ft_here_set(int argc, char	**argv, char **env);
int		ft_temp_set(t_data *d);
int		ft_strncmp(const char *s1, const char *s2);
char	*set_path(t_data *d, char *com);
/*ERROR*/
int		ft_error_command(char **env, char *s);
int		ft_error_file(int argc, char **argv, int i);

/*GNL*/
char	*get_next_line(int fd);

#endif