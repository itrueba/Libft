/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:08:13 by itrueba-          #+#    #+#             */
/*   Updated: 2022/12/09 11:06:44 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s_list;

	s_list = (t_list *)malloc(sizeof(*s_list));
	if (!s_list)
		return (NULL);
	s_list->content = content;
	s_list->next = NULL;
	return (s_list);
}
