/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 14:28:20 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/20 14:00:43 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	del(void *ptr)
// {
// 	ptr = NULL;
// }

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && del != NULL)
	{
		(*del)(lst->content);
		free(lst);
	}
}

// int	main(void)
// {
// 	t_list	*head = NULL;
// 	t_list	*temp;
// 	int	value1 = 10;
// 
// 	temp = ft_lstnew(&value1);
// 	ft_lstadd_back(&head, temp);
// 	temp = head;
// 	ft_lstdelone(temp, del);
// 	return (0);
// }
