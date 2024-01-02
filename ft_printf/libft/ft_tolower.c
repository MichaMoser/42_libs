/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:50:19 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/10 12:26:39 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// int	main(int argc, char *argv[])
// {
// 	argc = 0;
// 	printf("%c", ft_tolower(argv[1][0]));
// 	return (0);
// }
