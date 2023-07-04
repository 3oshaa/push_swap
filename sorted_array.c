/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalketbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:51:24 by oalketbi          #+#    #+#             */
/*   Updated: 2022/02/07 14:39:09 by oalketbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static	void	ft_swap_arr(int size, int *arr)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
		i++;
	}
}

void	ft_sort_stack(t_list *stack, int *arr)
{
	int	*temp;
	int	size;

	size = ft_lstsize(stack);
	temp = arr;
	while (stack)
	{
		*temp = ft_atoi(stack->content);
		stack = stack->next;
		temp++;
	}
	while (ft_sorted_arr(arr, size))
		ft_swap_arr(size, arr);
}
