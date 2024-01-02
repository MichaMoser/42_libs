/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 10:38:12 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/18 11:16:17 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

// int	main(void)
// {
// 	int	i;
// 	t_list	*head = NULL;
// 	t_list	*tmp;
// 
// 	i = 0;
// 	while (i < 5)
// 	{
// 		tmp = ft_lstnew(&i);
// 		tmp->next = head;
// 		head = tmp;
// 		i++;
// 	}
// 	printf("%i\n", ft_lstsize(head));
// 	while (i > 0)
// 	{
// 		head = tmp;
// 		tmp = tmp->next;
// 		free(head);
// 		i--;
// 	}
// 	return (0);
// }
