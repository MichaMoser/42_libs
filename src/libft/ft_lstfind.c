/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:24:30 by mmoser            #+#    #+#             */
/*   Updated: 2024/07/22 12:52:22 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *head, bool (*is_x)(void *, char *), char *foo_arg)
{
	if (!head || !is_x)
		return (NULL);
	while (head)
	{
		if (is_x(head->as_ptr, foo_arg))
			return (head);
		head = head->next;
	}
	return (head);
}
