/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 11:07:38 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/13 11:50:27 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

// int	main(void)
// {
// 	char	*s = "Hello World";
// 	int	filedescriptor = open("test.txt", O_WRONLY);
// 	if (filedescriptor == -1)
// 		return (0);
// 	ft_putendl_fd(s, filedescriptor);
// 	int	result = close(filedescriptor);
// 	if (result == -1)
// 		return (0);
// }
