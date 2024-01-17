/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:56:48 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 12:48:28 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *) str;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (str);
}

// int	main(void)
// {
// //	char	str[] = "123456";
//	int		array[] = {1, 2, 3, 4, 5, 6}; 	

//	ft_memset(array, 255, 4);
//	printf("%s\n", str);
//	memset(array, 1, 2);
//	ft_memset(array, 0, sizeof(array));
// 	return (0);
// }
