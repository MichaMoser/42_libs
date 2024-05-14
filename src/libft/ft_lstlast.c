/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 11:16:44 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/20 14:09:19 by mmoser        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// void	del(void *ptr)
// {
// 	ptr = NULL;
// }

// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*tmp;
// 	t_list	*result;
// 	int	i;

// 	i = 0;
// 	while (i < 5)
// 	{
// 		tmp = ft_lstnew(&i);
// 		tmp->next = head;
// 		head = tmp;
// 		i++;
// 	}
// 	result = ft_lstlast(head);
// 	printf("%i\n", *(int *) (result->content));
// 	printf("%p\n", (int *) (result->next));
// 	ft_lstclear(&head, del);
// 	return (0);
// }
