/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/13 09:58:29 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/13 12:15:28 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

// void	uneven_exchanged_by_zero(unsigned int i, char *c)
// {
//     if (i % 2 != 0)
// 	*c = '_';
// }

// void	even_exchanged_by_zero(unsigned int i, char *c)
// {
//     if (i % 2 == 0)
// 	*c = '_';
// }

// int     main(void)
// {
//         char	s1[] = "Hello World";
//         char	s2[] = "Hello World";
// 	ft_striteri(s1, uneven_exchanged_by_zero); 
// 	ft_striteri(s2, even_exchanged_by_zero); 

//         printf("%s\n", s1);
//         printf("%s\n", s2);
// 	return (0);
// }
