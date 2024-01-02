/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 17:22:39 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 13:07:05 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		len = 0;
	else if (start + len > str_len)
		len = str_len - start;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

// int	main(void)
// {
// 	char const	s[] = "0123456789";
// 	char		*ptr = ft_substr(s, 100, 1);

// 	printf("%s\n", ptr);
// 	printf("%p\n", ptr);
// 	free(ptr);
// 	return (0);
// }
