/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 17:37:56 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 09:41:14 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && *s2 && n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char) *s1 - (unsigned char) *s2);
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

// int	main(void)
// {
// 	const char	*s1 = "abc";
// 	const char	*s2 = "ab\200d";
// 	size_t		n = 3;
// 
// 	printf("%i\n", strncmp(s1, s2, n));
// 	printf("%i", ft_strncmp(s1, s2, n));
// 	return (0);
// }
