/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 11:51:00 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 14:22:12 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_number_to_fd(int fd, long n)
{
	char	c;

	if (n / 10 == 0)
	{
		c = n % 10 + '0';
		write(fd, &c, 1);
		return ;
	}
	write_number_to_fd(fd, n / 10);
	c = n % 10 + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	long_n;

	long_n = (long) n;
	if (n < 0)
	{
		write(fd, "-", 1);
		long_n *= -1;
	}
	write_number_to_fd(fd, long_n);
}

// int	main(void)
// {
// 	int	filedescriptor = open("test.txt", O_WRONLY);
// 	if (filedescriptor == -1)
// 		return (0);
// 	ft_putnbr_fd(INT_MIN, filedescriptor);
// 	int	result = close(filedescriptor);
// 	if (result == -1)
// 		return (0);
// 	return (0);
// }
