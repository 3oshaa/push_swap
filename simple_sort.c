/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalketbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:39:36 by oalketbi          #+#    #+#             */
/*   Updated: 2022/02/07 14:51:24 by oalketbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_three(t_list **stack)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = ft_atoi((*stack)->content);
	num2 = ft_atoi((*stack)->next->content);
	num3 = ft_atoi((*stack)->next->next->content);
	if (num3 > num2 && num2 > num1)
		return (0);
	else if ((num1 > num2 && num2 < num3 && num1 < num3)
		|| (num1 < num2 && num3 < num2 && num1 < num3)
		|| (num1 > num2 && num2 > num3 && num1 > num3))
		ft_swap(stack, "sa\n");
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		ft_r(stack, "ra\n");
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		ft_rr(stack, "rra\n");
	ft_sort_three(stack);
	return (0);
}

void	ft_sort_five(t_list **a, t_list **b, int *s_arr)
{
	int	i;

	i = 0;
	while (i < 2 )
	{
		while (ft_atoi((*a)->content) != s_arr[i])
		{
			if (ft_atoi((*a)->content) == s_arr[1])
				ft_push(a, b, "pb\n");
			if (ft_has_value(*a, s_arr[i], s_arr[i]) <= ft_lstsize(*a) / 2)
				ft_r(a, "ra\n");
			else
				ft_rr(a, "rra\n");
		}
		ft_push(a, b, "pb\n");
		i++;
		if ((*b)->next && ft_atoi((*b)->content) < ft_atoi((*b)->next->content))
		{
			ft_swap(b, "sb\n");
			i++;
		}
	}
	ft_sort_three(a);
	while (*b)
		ft_push(b, a, "pa\n");
}
