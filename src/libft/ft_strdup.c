/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 11:52:25 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/20 16:05:17 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	strl;
	char	*cpy_s;

	strl = ft_strlen(s);
	cpy_s = malloc((strl + 1) * sizeof(char));
	if (cpy_s == NULL)
		return (0);
	ft_strlcpy(cpy_s, s, strl + 1);
	return (cpy_s);
}

// int	main(void)
// {
// 	const char	string[] = "123";
// 	char		*cpy_my;
// 	char		*cpy_og;
// 
// 	cpy_my = ft_strdup(string);
// 	cpy_og = strdup(string);
// 	printf("%s\n", cpy_my);
// 	printf("%p\n\n", cpy_my);
// 	printf("%s\n", cpy_og);
// 	printf("%p\n", cpy_og);
// 	free(cpy_my);
// 	free(cpy_og);
// 	return (0);
// }
