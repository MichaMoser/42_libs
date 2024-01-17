/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/02 18:40:14 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/10 12:25:35 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// int	main(int argc, char *argv[])
// {
// 	argc = 3;
// 	printf("%i", ft_isalpha(argv[1][0]));

// 	return (0);
// }
