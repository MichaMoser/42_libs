/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 11:31:01 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 16:15:42 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	i = 0;
	ptr_d = (unsigned char *) dest;
	ptr_s = (unsigned char *) src;
	if (ptr_d == 0 && ptr_s == 0)
		return (0);
	while (i < n)
	{
		ptr_d[i] = ptr_s[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char		dest[8]	;
// 	const char	src[] = "abcde";
// 	size_t		n = 3;
// 
// 	ft_memcpy((void *) 0, (void *) 0, n);
// 	printf("%s", (char *) dest);
// 	return (0);
// }
