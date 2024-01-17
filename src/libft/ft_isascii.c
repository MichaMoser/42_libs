/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:28:45 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/10 12:25:39 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int	main(int argc, char *argv[])
// {
// 	argc = 3;

// 	printf("%i", ft_isascii(argv[1][0]));
// 	return (0);
// }
