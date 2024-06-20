/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occurrences.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:50:30 by mmoser            #+#    #+#             */
/*   Updated: 2024/06/20 14:18:42 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_occurrences(const char *str, const char *set)
{
	size_t	i;
	size_t	count;

	if (!str)
	{
		return (-1);
	}
	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strchr(set, str[i]))
		{
			count++;
		}
		i++;
	}
	return (count);
}
