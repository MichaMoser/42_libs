/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 13:33:35 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/16 13:48:36 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!dst || !src || !size)
		return (-1);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	i = 0;
	while (i < size - dst_len - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int     main(void)
// {
//         char    dest[8] = "0123456";    
//         char    src[21] = "aaabbb123456789xxxxx";    
//         char    dest2[8] = "0123456";   
//         char    src2[21] = "aaabbb123456789xxxxx";

//         printf("%zu\n", ft_strlcat(dest, src, 10));     
//         printf("%s\n", dest);   
//         printf("%zu\n", strlcat(dest2, src2, 10));      
//         printf("%s\n", dest2);  
//         return (0);
// }
