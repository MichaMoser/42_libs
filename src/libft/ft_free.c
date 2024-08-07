/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:12:37 by mmoser            #+#    #+#             */
/*   Updated: 2024/08/07 16:38:19 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_2d_array(void **arr)
{
	size_t	y;

	y = 0;
	if (!arr)
	{
		return ;
	}
	if (!arr[0])
	{
		free(arr);
		return ;
	}
	while (arr[y])
	{
		free(arr[y]);
		y++;
	}
	free(arr);
}

void	sfree(void **ptr)
{
	if (!ptr || !*ptr)
		return ;
	free(*ptr);
	*ptr = NULL;
}
