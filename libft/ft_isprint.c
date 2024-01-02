/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 12:47:46 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/10 12:25:46 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int	main(int argc, char *argv[])
// {
// 	argc = 0;
// 	printf("%i", ft_isprint(argv[1][0]));
// 	return (0);
// }
