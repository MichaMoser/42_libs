/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:34:45 by mmoser            #+#    #+#             */
/*   Updated: 2024/08/03 15:43:54 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BUFFER_SIZE 1024

static int	fd_storage(int new_fd, bool set)
{
	static int	fd;

	if (set)
		fd = new_fd;
	return (fd);
}

static int	get_fd(void)
{
	int	fd;

	fd = fd_storage(0, false);
	if (fd == 0)
		fd = STDOUT_FILENO;
	return (fd);
}

void	set_fd(int fd)
{
	fd_storage(fd, true);
}

static void	empty_buffer(char *buffer, size_t *count, size_t *pos)
{
	int	fd;

	fd = get_fd();
	*count += write(fd, buffer, *pos);
	ft_bzero(buffer, *pos);
	*pos = 0;
}

int	ft_buffered_putchar(const char c, int amount)
{
	static char		buffer[BUFFER_SIZE];
	static size_t	count;
	static size_t	i;
	size_t			temp;

	if (amount == RESET)
	{
		empty_buffer(buffer, &count, &i);
		return (temp = count, count = 0, temp);
	}
	while (amount > 0)
	{
		if (i == BUFFER_SIZE - 1)
		{
			empty_buffer(buffer, &count, &i);
		}
		buffer[i] = c;
		i++;
		amount--;
	}
	return (count);
}
