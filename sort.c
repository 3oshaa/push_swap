/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalketbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:50:50 by oalketbi          #+#    #+#             */
/*   Updated: 2022/02/07 11:06:25 by oalketbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_lower_chunck(t_list **a, t_list **b, int l_v, int h_v)
{
	int	num;

	ft_push(a, b, "pb\n");
	if ((*b)->next)
	{
		if (*a)
			num = ft_atoi((*a)->content);
		if ((*a) && !(num <= h_v && num >= l_v)
			&& ft_has_value(*a, l_v, h_v) <= ft_lstsize(*a) / 2)
		{
			ft_r(b, "rr\n");
			ft_r(a, "");
		}
		else
			ft_r(b, "rb\n");
	}
}

static	int	ft_set_i(int len)
{
	int	i;

	if (len == 500)
		i = 30;
	else if (len > 20)
		i = 10;
	else
		i = 3;
	return (i);
}

void	ft_update_limit(int *lower_limit, int *higher_limit, int len, int i)
{
	*lower_limit = *lower_limit - i;
	*higher_limit = *higher_limit + i;
	if (*lower_limit < 0)
		*lower_limit = 0;
	if (*higher_limit >= len)
		*higher_limit = len - 1;
}

void	ft_push_to_b(t_list **a, t_list **b, int *s_arr, int len)
{
	int	l_l;
	int	h_l;
	int	num;

	l_l = len / 2 - ft_set_i(len);
	h_l = len / 2 + ft_set_i(len) - 1;
	while (*a)
	{
		while (ft_has_value(*a, s_arr[l_l], s_arr[h_l]))
		{
			num = ft_atoi((*a)->content);
			if (num >= s_arr[l_l] && num < s_arr[len / 2])
				ft_lower_chunck(a, b, s_arr[l_l], s_arr[h_l]);
			else if (num >= s_arr[len / 2] && num <= s_arr[h_l])
				ft_push(a, b, "pb\n");
			else
			{
				if (ft_has_value(*a, s_arr[l_l], s_arr[h_l]) <= ft_lstsize(*a))
					ft_r(a, "ra\n");
				else
					ft_rr(a, "rra\n");
			}
		}
		ft_update_limit(&l_l, &h_l, len, ft_set_i(len));
	}
}

void	ft_push_to_a(t_list **a, t_list **b, int *sorted_arr, int len)
{
	int	i;

	i = 1;
	while (*b)
	{
		while (ft_atoi((*b)->content) != sorted_arr[len - i])
		{
			if (ft_atoi((*b)->content) == sorted_arr[len - 1 - i])
				ft_push(b, a, "pa\n");
			if (ft_has_value(*b, sorted_arr[len - i], sorted_arr[len - i])
				<= ft_lstsize(*b) / 2)
				ft_r(b, "rb\n");
			else
				ft_rr(b, "rrb\n");
		}
		ft_push(b, a, "pa\n");
		i++;
		if ((*a)->next && ft_atoi((*a)->content) > ft_atoi((*a)->next->content))
		{
			ft_swap(a, "sa\n");
			i++;
		}
	}
}
