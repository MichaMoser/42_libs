/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 11:29:58 by mmoser        #+#    #+#                 */
/*   Updated: 2023/11/13 17:11:12 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_and_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

char	*ft_simple_calloc(size_t size_to_allocate)
{
	char	*result;
	size_t	i;

	i = 0;
	result = malloc(size_to_allocate * sizeof(char));
	if (!result)
		return (NULL);
	while (i < size_to_allocate)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

char	*replace_str(char *src, size_t size_to_allocate, bool free_source)
{
	size_t	i;
	size_t	src_len;
	char	*cpy_s;

	cpy_s = ft_simple_calloc(size_to_allocate * sizeof(char));
	if (cpy_s == NULL)
	{
		if (free_source == 1)
			ft_free_and_null(&src);
		return (NULL);
	}
	i = 0;
	src_len = ft_strlen(src);
	while (i < src_len && i < size_to_allocate - 1)
	{
		cpy_s[i] = src[i];
		i++;
	}
	if (free_source == 1)
		ft_free_and_null(&src);
	return (cpy_s);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if ((char) c == '\0')
		return ((char *) s);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (NULL);
}
