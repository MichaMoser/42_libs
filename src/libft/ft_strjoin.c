/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 17:48:23 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/16 10:03:51 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	strlen;
	size_t	l1;
	size_t	l2;

	if (s1)
		l1 = ft_strlen(s1);
	else
	 	l1 = 0;
	if (s2)
		l2 = ft_strlen(s2);
	else
		l2 = 0;
	strlen = l1 + l2;
	result = malloc((strlen + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	ft_memcpy(result, s1, l1);
	ft_memcpy(&result[l1], s2, l2);
	result[strlen] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char const	s1[] = "Hello ";
// 	char const	s2[] = "world";
// 	char		*result = ft_strjoin(s1, s2);

// 	printf("%s\n", result);
// 	free(result);	
// }
