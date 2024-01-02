/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 16:35:04 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 14:23:55 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*ptr;
// 	char	*ptr2;
// 	const char	*str = "aa1bb1cc1d";
// 	int	c = '\0';
// 
// 	ptr = ft_strrchr(str, c);
// 	ptr2 = strrchr(str, c);
// 	printf("My: %c and %p\n", *ptr, ptr);
// 	printf("Og: %c and %p", *ptr2, ptr2);
// 	return (0);
// }
