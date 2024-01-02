/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 09:31:00 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/23 14:35:33 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newnode)
{
	if (newnode != NULL)
	{
		newnode->next = *lst;
		*lst = newnode;
	}
}

// void	del(void *ptr)
// {
// 	ptr = NULL;
// }

// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*tmp;
// 	int	value = 42;

// 	tmp = ft_lstnew((void *) &value);
// 	ft_lstadd_front(&head, tmp);
// 	while (tmp->next != NULL)
// 	{
// 		printf("%i - ", *(int *) (tmp->content));
// 		tmp = tmp->next;
// 	}
// 	printf("%i - ", *(int *) (tmp->content));
// 	printf("\n");
// 	ft_lstclear(&head, del);
// 	return (0);
// }
