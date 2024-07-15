/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:59:35 by mmoser            #+#    #+#             */
/*   Updated: 2024/07/15 12:21:48 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_whitespace(char c)
{
	if (ft_strchr(WHITESPACES, c) == NULL)
	{
		return (false);
	}
	return (true);
}

bool	ft_ends_on(char *str, char c)
{
	if (!str || !*str)
		return (false);
	return (str[ft_strlen(str) - 1] == c);
}
