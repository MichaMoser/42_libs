/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 11:02:16 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/20 15:21:18 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

// int	main(void)
// {
// 	char	s[] = "Hello World";
// 	int	filedescriptor = open("test.txt", O_WRONLY);

// 	if (filedescriptor == -1)
// 		return (0);
// 	ft_putstr_fd(s, filedescriptor);
// 	int	result = close(filedescriptor);
// 	if (result == -1)
// 		return (0);
// 	return (0);
// }
