/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 11:30:16 by mmoser        #+#    #+#                 */
/*   Updated: 2023/11/07 13:29:05 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdbool.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# define FD_MAX 1024

char	*get_first_lbreak(int fd, char **prev_excessread);
char	*split_off_excessread(char **str_incl_first_lb, char *lbreak);
char	*get_next_line(int fd);

char	*replace_str(char *src, size_t size_to_allocate, bool free_source);
char	*ft_simple_calloc(size_t size_to_allocate);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	ft_free_and_null(char **ptr);

#endif
