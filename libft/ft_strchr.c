/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:53:35 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/13 13:41:16 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	if ((char) c == '\0')
		return ((char *) s);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*ptr;
// 	char	*ptr2;
// 	const char	*str = "teste";
// 	int	c = '\0';
// 
// 	ptr = ft_strchr(str, c);
// 	ptr2 = strchr(str, c);
// 	printf("My: %c and %p\n", *ptr, ptr);
// 	printf("Og: %c and %p", *ptr2, ptr2);
// 	return (0);
// }
