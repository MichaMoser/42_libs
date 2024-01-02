/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 09:45:47 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/24 10:13:15 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_allocated_mem(char **array, int ar_i)
{
	while (ar_i >= 0)
	{
		free(array[ar_i]);
		ar_i--;
	}
	free(array);
	return (0);
}

static size_t	wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static char	**create_array(char const *s, char c)
{
	char	**array;

	array = (char **) malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (array == NULL)
		return (0);
	return (array);
}

static void	initialize_variables_to_0(size_t *ar_i, size_t *str_i)
{
	*ar_i = 0;
	*str_i = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	ar_i;
	size_t	str_i;
	size_t	word_len;

	array = create_array(s, c);
	if (array == NULL)
		return (0);
	initialize_variables_to_0(&ar_i, &str_i);
	while (ar_i < wordcount(s, c))
	{
		while (s[str_i] == c && s[str_i])
			str_i++;
		word_len = 0;
		while (s[str_i + word_len] != c && s[str_i + word_len])
			word_len++;
		array[ar_i] = (char *) malloc((word_len + 1) * sizeof(char));
		if (array[ar_i] == NULL)
			return (free_allocated_mem(array, (int) ar_i - 1));
		ft_strlcpy(array[ar_i], &s[str_i], word_len + 1);
		str_i += word_len;
		ar_i++;
	}
	array[ar_i] = 0;
	return (array);
}

// int	main(void)
// {
//  	char const	*s = "  Hello How does this work ";
// 	char		c = ' ';
//  	char		**result = ft_split(s, c);
//       	size_t		nb_of_words = wordcount(s, c);
// 
// 	while (nb_of_words + 1 > 0)
// 	{
// 		free(result[nb_of_words]);
// 		nb_of_words--;
// 	}
// 	free (result);
// 	return (0);
// }
