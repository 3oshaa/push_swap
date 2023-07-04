/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalketbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:49:35 by oalketbi          #+#    #+#             */
/*   Updated: 2022/02/07 10:13:03 by oalketbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "push_swap.h"

void	*ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	len;
	int	*sorted_arr;

	len = ft_lstsize(*stack_a);
	sorted_arr = malloc(sizeof(int) * len);
	if (!sorted_arr)
		return (NULL);
	ft_sort_stack(*stack_a, sorted_arr);
	if (len == 3)
		ft_sort_three(stack_a);
	else if (len == 5)
		ft_sort_five(stack_a, stack_b, sorted_arr);
	else
	{
		ft_push_to_b(stack_a, stack_b, sorted_arr, len);
		ft_push_to_a(stack_a, stack_b, sorted_arr, len);
	}
	free(sorted_arr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_createlist(argc, argv);
	if (!stack_a || !ft_sorted(stack_a))
	{
		ft_stack_delet(&stack_a);
		exit (0);
	}
	else
		ft_sort(&stack_a, &stack_b);
	ft_stack_delet(&stack_a);
	return (0);
}
