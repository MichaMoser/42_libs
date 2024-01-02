/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 11:30:09 by mmoser        #+#    #+#                 */
/*   Updated: 2023/11/14 09:29:21 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_first_lbreak(int fd, char **prev_excessread)
{
	char	*buffer;
	int		bytes_read;

	buffer = *prev_excessread;
	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && !ft_strchr(buffer, '\n'))
	{
		buffer = replace_str(buffer, ft_strlen(buffer) + BUFFER_SIZE + 1, 1);
		*prev_excessread = NULL;
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, &buffer[ft_strlen(buffer)], BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_free_and_null(&buffer);
			return (NULL);
		}
	}
	if (bytes_read != BUFFER_SIZE)
		buffer = replace_str(buffer, ft_strlen(buffer) + 1, 1);
	return (buffer);
}

char	*split_off_excessread(char **str_incl_first_lb, char *lbreak)
{
	char	*excessread;
	size_t	len_nline;

	excessread = replace_str(lbreak + 1, ft_strlen(lbreak + 1) + 1, 0);
	if (!excessread)
	{
		ft_free_and_null(str_incl_first_lb);
		return (NULL);
	}
	len_nline = lbreak + 1 - *str_incl_first_lb;
	*str_incl_first_lb = replace_str(*str_incl_first_lb, len_nline + 1, 1);
	if (*str_incl_first_lb == 0)
	{
		ft_free_and_null(&excessread);
		return (NULL);
	}
	return (excessread);
}

char	*get_next_line(int fd)
{
	char		*str_incl_first_lb;
	char		*lbreak;
	static char	*excess_read;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	str_incl_first_lb = get_first_lbreak(fd, &excess_read);
	if (str_incl_first_lb == NULL)
		return (NULL);
	if (*str_incl_first_lb == '\0')
	{
		ft_free_and_null(&str_incl_first_lb);
		return (NULL);
	}
	lbreak = ft_strchr(str_incl_first_lb, '\n');
	if (lbreak && ft_strlen(lbreak + 1))
	{
		excess_read = split_off_excessread(&str_incl_first_lb, lbreak);
		if (!excess_read)
			return (NULL);
	}
	else
		excess_read = 0;
	return (str_incl_first_lb);
}

// int main(void)
// {
// 	int fd = open("variable_nls.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("opening file failed\n");
// 		return (0);
// 	}
// 	char *s;
//
// 	s = get_next_line(fd);
// 	printf("nl:%s", s);
// 	free (s);
// 	s = get_next_line(fd);
// 	printf("nl:%s", s);
// 	free (s);
// 	s = get_next_line(fd);
// 	printf("nl:%s", s);
// 	free (s);
// 	s = get_next_line(fd);
// 	printf("nl:%s", s);
// 	free (s);
// 	s = get_next_line(fd);
// 	printf("nl:%s", s);
// 	free (s);
// 	return (0);
// }
