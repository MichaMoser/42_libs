/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 09:17:17 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/16 11:37:04 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comp_to_set(char const s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	strlen;
	size_t	result_strlen;

	i = 0;
	while (s1[i] && comp_to_set(s1[i], set) == 1)
		i++;
	strlen = ft_strlen(s1);
	if (s1[i] == '\0')
		result_strlen = 0;
	else
	{
		j = 0;
		while (strlen - j > 0 && comp_to_set(s1[strlen - j - 1], set) == 1)
			j++;
		result_strlen = strlen - i - j;
	}
	result = malloc((result_strlen + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	ft_memcpy(result, &s1[i], result_strlen);
	result[result_strlen] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char const	string[] = "   xxxtripouille";
// 	char const	charset[] = " x";
// 	char		*result = ft_strtrim(string, charset);

// 	printf("%s\n", result);
// 	free(result);
// 	return (0);
// }
