/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 16:29:20 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/20 12:14:18 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	del(void *ptr)
// {
// 	ptr = NULL;
// }

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || del == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current != NULL)
	{
		del(current->content);
		next = current->next;
		free(current);
		current = next;
	}
	(*lst) = NULL;
}

// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*tmp;
// 	t_list	**start_clear;
// 	int	v1 = 10;
// 	int	v2 = 55;
// 	int	v3 = 20;
// 
// 	size_t	i = 0;
// 	while (i < 3)
// 	{
// 		tmp = ft_lstnew(&v1);
// 		ft_lstadd_back(&head, tmp);
// 		i++;
// 	}
// 	start_clear = &(tmp->next);
// 	tmp = ft_lstnew(&v2);
// 	ft_lstadd_back(&head, tmp);
// 	i = 0;
// 	while (i < 3)
// 	{
// 		tmp = ft_lstnew(&v3);
// 		ft_lstadd_back(&head, tmp);
// 		i++;
// 	}
// 	i = 0;
// 	tmp = head;
// 	while (tmp->next != NULL)
// 	{
// 		printf("%i - ", *(int *)(tmp->content));
// 		tmp = tmp->next;
// 	}
// 	printf("%i - \n", *(int *)(tmp->content));
// 	ft_lstclear(start_clear, del);
// 	tmp = head;
// 	i = 0;
// 	while (tmp->next != NULL)
// 	{
// 		printf("%i - ", *(int *)(tmp->content));
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	printf("%i - ", *(int *)(tmp->content));
// 	ft_lstclear(&head, del);
// 	return (0);
// }
