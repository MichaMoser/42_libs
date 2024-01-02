/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 18:45:06 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/16 10:04:14 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			strl;
	unsigned int	i;

	strl = ft_strlen(s);
	result = (char *) malloc((strl + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	i = 0;
	while (i < strl)
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// char	uneven_exchanged_by_zero(unsigned int i, char c)
// {
// 	if (i % 2 != 0)
// 		return ('_');
// 	return (c);
// }

// char	even_exchanged_by_zero(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return ('_');
// 	return (c);
// }

// int	main(void)
// {
// 	char const	*s = "Hello World";
// 	char	*result1 = ft_strmapi(s, uneven_exchanged_by_zero); 
// 	char	*result2 = ft_strmapi(s, even_exchanged_by_zero); 

// 	printf("%s\n", result2);
// 	free(result2);
// 	return (0);
// }
