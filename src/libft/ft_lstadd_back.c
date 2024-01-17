/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 11:46:40 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/20 11:50:32 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp == NULL)
		*lst = new;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}

// void	del(void *ptr)
// {
// 	ptr = NULL;
// }

// int	main(void)
// {
// 	t_list *head = NULL;
// 	t_list *tmp;
// 	size_t	i = 0;
// 	size_t	value = 10;

// 	while (i < 5)
// 	{
// 		tmp = ft_lstnew(&value);
// 		ft_lstadd_back(&head, tmp);
// 		i++;
// 	}
// 	tmp = head;
// 	while (tmp->next != NULL)
// 	{
// 		printf("%i - ", *(int *) tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("%i - ", *(int *) tmp->content);
// 	ft_lstclear(&head, del);
// 	return (0);
// }
