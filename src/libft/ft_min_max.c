/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:52:03 by mmoser            #+#    #+#             */
/*   Updated: 2024/04/24 10:52:21 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int num1, int num2)
{
	if (num1 < num2)
	{
		return (num1);
	}
	else
	{
		return (num2);
	}
}

int	ft_max(int num1, int num2)
{
	if (num1 > num2)
	{
		return (num1);
	}
	else
	{
		return (num2);
	}
}
