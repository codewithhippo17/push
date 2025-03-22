/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamza <ehamza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:59:04 by ehamza            #+#    #+#             */
/*   Updated: 2025/03/22 20:23:19 by ehamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*read_buffer(int fd);
void	fill_word(int fd, char **word, char **line, char **newline_pos);
void	ft_save(char **reminder, char *buffer);
char	*ft__last(char	*line);
char	*ft__strjoin(char *s1, char *s2);
char	*ft__memchr(char *str);
char	*ft__strdup(char *s);
size_t	ft__strlen(const char *str);

#endif