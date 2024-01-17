/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 10:41:01 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/13 10:53:06 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	int	filedescriptor = open("test.txt", O_WRONLY);
// 	if (filedescriptor == -1)
// 		return (0);
// 	ft_putchar_fd('a', filedescriptor);

// 	int result = close(filedescriptor);
// 	if (result == -1)
// 		return (0);
// 	return (0);
// }
