/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:33:53 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/05/25 14:36:31 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd);
int		ft_check_jump(void);
int		ft_strjoin(int fd);
char	*ft_final(void);
int		ft_clear(void);
char	*ft_savst(char *str, int i);
int		ft_len(char *s);

#endif