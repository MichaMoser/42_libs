/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:59:35 by mmoser            #+#    #+#             */
/*   Updated: 2024/04/30 10:54:33 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_whitespace(char c)
{
	if (ft_strchr(WHITESPACES, c) == NULL)
	{
		return (false);
	}
	return (true);
}
