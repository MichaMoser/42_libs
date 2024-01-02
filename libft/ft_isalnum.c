/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 10:45:59 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/10 12:25:31 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// int	main(int argc, char *argv[])
// {
// 	argc = 0;
// 	printf("%i", ft_isalnum(argv[1][0]));
// 	return (0);
// }
