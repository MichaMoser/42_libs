/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 11:30:37 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/16 13:48:24 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			arr_size;

	if (nmemb * size != 0 && nmemb > INT_MAX / size)
		return (0);
	else
		arr_size = nmemb * size;
	ptr = (unsigned char *) malloc(arr_size * sizeof(char));
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, arr_size);
	return ((void *) ptr);
}

// int	main(void)
// {
// 	unsigned char	*ptr;	
// 	size_t		nmemb = 5;
// 	size_t		size = 10;

// 	ptr = ft_calloc(nmemb, size);
// 	free ((unsigned char *) ptr);
// 	return (0);
// }
