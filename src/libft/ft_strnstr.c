/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 12:34:32 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 16:29:14 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *) big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && little[j] && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *) &big[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char	s[]= "a";
// 	const char	big[]= "aaabcabcd";
// 	const char	little[]= "abcd";
// 	size_t	len = 17;
// 
// 	printf("%p\n", ft_strnstr(s, s, 4));
// 	printf("%p\n", strnstr(s, s, 4));
// 	// printf("%s\n", ft_strnstr(big, little, len));
// 	// printf("%s\n", strnstr(big, little, len));
// 	return (0);
// }
