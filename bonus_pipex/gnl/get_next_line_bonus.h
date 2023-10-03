/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoikoet <jgoikoet@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:33:53 by jgoikoet          #+#    #+#             */
/*   Updated: 2023/05/25 15:00:57 by jgoikoet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_read_b(int fd);
int		ft_check_jump_b(int fd);
int		ft_strjoin_b(int fd);
char	*ft_final_b(int fd);
int		ft_clear_b(int fd);
char	*ft_s(char *str, int i, int fd);
int		ft_le(char *s);

#endif