/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 11:43:34 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 11:19:02 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

// int	main(void)
// {
// 	char	dest[8] = "0123456";	
// 	char	src[16] = "aaabbb123456789";	
// 	char	dest2[8] = "0123456";	
// 	char	src2[16] = "aaabbb123456789";

// 	printf("%zu\n", ft_strlcpy(dest, src, 11));	
// 	printf("%s\n", dest);	
// 	printf("%zu\n", strlcpy(dest2, src2, 11));	
// 	printf("%s\n", dest2);	
// 	return (0);
// }
