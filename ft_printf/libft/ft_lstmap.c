/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 13:51:09 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/20 11:37:44 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_temp;

	new_head = NULL;
	if (lst == NULL || (*f) == NULL || (*del) == NULL)
		return (0);
	while (lst != NULL)
	{
		new_temp = ft_lstnew((*f)(lst->content));
		if (new_temp == NULL)
		{
			ft_lstclear(&new_head, del);
			return (0);
		}
		ft_lstadd_back(&new_head, new_temp);
		lst = lst->next;
	}
	return (new_head);
}

//void  del(void *ptr)
//{
//    ptr = NULL;
//}
//
//void	*exchange_by_a(void *ptr)
//{
//	char	*str;
//
//	str = ptr;
//	while (*str)
//	{
//		*str = 'a';
//		str++;
//	}
//	return (ptr);
//}
//
//int	main(void)
//{
//	t_list	*head = NULL;
//	t_list	*temp;
//	t_list	*result;
//	size_t	i = 0;
//	char	str[] = "abc";
//
//	while (i < 5)
//	{
//		temp = ft_lstnew((void *) str);
//		ft_lstadd_back(&head, temp);
//		i++;
//	}
//	temp = head;
//	while (temp->next != NULL)
//	{
//		printf("%s -", (char *) (temp->content));
//		temp = temp->next;
//	}
//	printf("%s -", (char *) (temp->content));
//	result = ft_lstmap(head, exchange_by_a, del); 
//	temp = result;
//	while (temp->next != NULL)
//	{
//		printf("%s -", (char *) (temp->content));
//		temp = temp->next;
//	}
//	printf("%s -", (char *) (temp->content));
//	ft_lstclear(&head, del);
//	ft_lstclear(&result, del);
//	return (0);
//}
