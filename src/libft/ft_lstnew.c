/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                     +:+                    */
/*   By: mmoser <mmoser@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/18 09:18:27 by mmoser        #+#    #+#                 */
/*   Updated: 2023/10/20 11:15:42 by mmoser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = malloc(sizeof(t_list));
	if (result == NULL)
		return (0);
	result->content = content;
	result->next = NULL;
	return (result);
}

// int	main(void)
// {
// 	t_list	*new_node = ft_lstnew((void *) 42);
// 	printf("%s\n", (char *) (new_node->content));
// 	free (new_node);
// 	return (0);
// }
