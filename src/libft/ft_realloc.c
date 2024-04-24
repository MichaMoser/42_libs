/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:03:41 by mmoser            #+#    #+#             */
/*   Updated: 2024/04/24 12:10:26 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void	*new;

	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(new_size);
	if (!new)
	{
		return (NULL);
	}
	if (ptr)
	{
		ft_memcpy(new, ptr, ft_min(new_size, old_size));
	}
	free(ptr);
	return (new);
}
