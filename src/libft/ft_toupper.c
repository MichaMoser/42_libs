/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:37:27 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/10 12:26:42 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// int	main(int argc, char *argv[])
// {
// 	argc = 0;
// 	printf("%c", ft_toupper(argv[1][0]));
// 	return (0);
// }
