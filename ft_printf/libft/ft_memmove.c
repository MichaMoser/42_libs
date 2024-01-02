/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 14:54:25 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 16:18:02 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	ptr_d = (unsigned char *) dest;
	ptr_s = (unsigned char *) src;
	if (ptr_d == 0 && src == 0)
		return (0);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			ptr_d[n - 1] = ptr_s[n - 1];
			n--;
		}
	}
	return (dest);
}

//int	main(void)
//{
// 	char	dest[10] = "123abcde";
// 	char	dest2[10] = "123abcde";
// 	char	dest3[10] = "123abcde";
// 	char	dest4[10] = "123abcde";
// 	char	dest5[10] = "123abcde";
// 	char	dest6[10] = "123abcde";
// 	char	src[10] = "xxxxxxx";
//	int	array[] = {1, 2, 3, INT_MAX, 5};
//	int	array2[] = {1, 2, 3, INT_MAX, 5};

// 	printf("My:\n%s\n", (char *)ft_memmove(dest, dest, 5));
// 	printf("%s\n", (char *)ft_memmove(dest2 + 6, dest2, 5));
//	ft_memmove(array + 1, array + 3, 4);           // works but no idea why
// 	printf("%s\n\n", (char *)ft_memmove(dest3, src, 10));
// 	printf("OG:\n%s\n", (char *)memmove(dest4, dest4, 5));
// 	printf("%s\n", (char *)memmove(dest5+6, dest5, 5));
//	memmove(array2 + 1, array2 + 3, 4);
// 	printf("%s\n\n", (char *) memmove(dest6, src, 10));
// 	return (0);
//} 
