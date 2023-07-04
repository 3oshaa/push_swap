/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalketbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:15:26 by oalketbi          #+#    #+#             */
/*   Updated: 2022/02/08 14:25:15 by oalketbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char *str)
{
	void	*temp;
	t_list	*ptr;

	if (*stack && (*stack)->next)
	{
		ptr = (*stack)->next;
		temp = (*stack)->content;
		(*stack)->content = ptr->content;
		ptr->content = temp;
		if (str)
			write (1, str, ft_strlen(str));
	}
}

void	ft_r(t_list **stack, char *str)
{
	t_list	*temp;

	if (*stack && ft_lstsize(*stack) > 1)
	{
		temp = ft_lstlast(*stack);
		temp->next = *stack;
		*stack = (*stack)->next;
		(temp->next)->next = NULL;
		if (str)
			write (1, str, ft_strlen(str));
	}
}

void	ft_rr(t_list **stack, char *str)
{
	t_list	*last;
	t_list	*temp;

	if (*stack && ft_lstsize(*stack) > 1)
	{
		last = ft_lstlast(*stack);
		temp = *stack;
		while (temp->next != last)
			temp = temp->next;
		temp->next = NULL;
		last->next = *stack;
		*stack = last;
		if (str)
			write (1, str, ft_strlen(str));
	}
}

void	ft_push(t_list **stack1, t_list **stack2, char *str)
{
	t_list	*temp;

	if (*stack1)
	{
		temp = *stack1;
		*stack1 = temp->next;
		if (!(*stack2))
		{
			*stack2 = temp;
			(*stack2)->next = NULL;
		}
		else
			ft_lstadd_front(stack2, temp);
		write (1, str, ft_strlen(str));
	}
}
