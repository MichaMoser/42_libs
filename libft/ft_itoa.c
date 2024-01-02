/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 13:32:57 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 14:21:30 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_string(char *result, long n, size_t strl)
{
	if (n / 10 == 0)
	{
		result[strl - 1] = n % 10 + '0';
		return ;
	}
	fill_string(result, n / 10, strl - 1);
	result[strl - 1] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	strl;
	int		temp;

	temp = n;
	strl = 1;
	while (temp / 10 != 0)
	{
		temp /= 10;
		strl++;
	}
	if (n < 0)
		strl++;
	result = malloc((strl + 1) * sizeof(char));
	if (result == NULL)
		return (0);
	if (n < 0)
	{
		result[0] = '-';
		fill_string(result + 1, (long) n * (-1), strl - 1);
	}
	else
		fill_string(result, n, strl);
	result[strl] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char	*result = ft_itoa(1000);
// 	printf("%s", result);
// 	free(result);
// 	return (0);
// }
