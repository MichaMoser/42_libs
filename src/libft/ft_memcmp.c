/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 10:44:15 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 11:28:25 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// does not work with a terminator 0 inside the string

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *) s1;
	ptr2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const void	*s1 = "1121";
// 	const void	*s2 = "\200";
// 	size_t		n = 10;
// 
// 	printf("%i\n", ft_memcmp(s1, s2, n));
// 	printf("%i\n", memcmp(s1, s2, n));
// 	return (0);
// }
