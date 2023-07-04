/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalketbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:52:23 by oalketbi          #+#    #+#             */
/*   Updated: 2022/02/21 11:50:56 by oalketbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_message(char **num)
{
	char	**temp;

	write(2, "Error\n", 6);
	temp = num;
	while (*num)
	{
		free (*num);
		num++;
	}
	free(temp);
	exit(1);
}

static	void	ft_check_double(char **temp, int i)
{
	int	j;
	int	len;

	j = 0;
	while (j < i)
	{
		if (ft_strlen(temp[i]) > ft_strlen(temp[j]))
			len = ft_strlen(temp[i]);
		else
			len = ft_strlen(temp[j]);
		if (!ft_strncmp(temp[i], temp[j], len))
			ft_error_message(temp);
		j++;
	}
}

void	ft_check_input(char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (temp[i][j] == '-' || temp[i][j] == '+' )
				j++;
			if (!ft_isdigit(temp[i][j++]))
				ft_error_message(temp);
		}
		if (ft_atol(temp[i]) > INT_MAX || ft_atol(temp[i]) < INT_MIN)
			ft_error_message(temp);
		ft_check_double(temp, i);
		i++;
	}
}

int	ft_last_value_loc(t_list *stack, int value, int value2)
{
	int	i;
	int	x;

	i = 0;
	while (stack)
	{
		i++;
		if (ft_atoi(stack->content) <= value2
			&& ft_atoi(stack->content) >= value)
			x = i;
		stack = stack->next;
	}
	return (x);
}

int	ft_has_value(t_list *stack, int value, int value2)
{
	int	i;
	int	x;
	int	len;

	len = ft_lstsize(stack);
	x = ft_last_value_loc(stack, value, value2);
	i = 0;
	while (stack)
	{
		i++;
		if (ft_atoi(stack->content) <= value2
			&& ft_atoi(stack->content) >= value)
		{
			if (len - x < i)
				return (x);
			else
				return (i);
		}
		stack = stack->next;
	}
	return (0);
}
