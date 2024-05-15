/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoser <mmoser@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:53:02 by mmoser            #+#    #+#             */
/*   Updated: 2024/05/15 11:53:27 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstjoin(t_list **head1, t_list *head2)
{
	t_list	*end;

	if (head1 && *head1)
	{
		end = ft_lstlast(*head1);
		end->next = head2;
	}
	else if (head1)
	{
		*head1 = head2;
	}
}
