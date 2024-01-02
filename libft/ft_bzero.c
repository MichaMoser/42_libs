/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 12:19:39 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 11:13:10 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

// int	main(void)
// {
// 	size_t	n;

// 	n = 4;
// 	char str[] = "123456789";
// 	ft_bzero(str, n);
// 	return(0);
// }
