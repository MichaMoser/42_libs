/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 12:19:01 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/20 14:06:14 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst == NULL || (*f) == NULL)
		return ;
	temp = lst;
	while (temp != NULL)
	{
		(*f)((temp->content));
		temp = temp->next;
	}
}

// void	cap_string(void *s)
// {
// 	char	*string;
// 
// 	string = (char *) s;
// 	while (*(char *) s)
// 	{
// 		*(char *) s = 'a';
// 		s++;
// 	}
// }
// 
// void del(void *ptr)                                    
// {
//      ptr = NULL;
// }
// 
// 
// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*temp;
// 	char	str[] = "abc";
// 
// 	size_t	i = 0;
// 	while(i < 5)
// 	{
// 		temp = ft_lstnew((void *) str);
// 		ft_lstadd_back(&head, temp);
// 		i++;
// 	}
// 	i = 0;
// 	temp = head;
// 	while (temp->next != NULL)
// 	{
// 		printf("%s - ", (char *)(temp->content));
// 		temp = temp->next;
// 	}
// 	printf("%s - \n", (char *)(temp->content));
// 	ft_lstiter(head, cap_string);
// 	temp = head;
// 	while (temp->next != NULL)
// 	{
// 		printf("%s - ", (char *)(temp->content));
// 		temp = temp->next;
// 	}
// 	printf("%s - ", (char *)(temp->content));
// 	ft_lstclear(&head, del);
// 	return (0);
// }
