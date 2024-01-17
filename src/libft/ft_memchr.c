/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 10:16:51 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/16 14:10:13 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return ((void *) &ptr[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const void	*s = "find the z";
// 	int			c = 'e';
// 	size_t		n = 12;

// 	printf("%p\n", ft_memchr(s, c, n));
// 	printf("%p", memchr(s, c, n));
// 	return (0);
// }