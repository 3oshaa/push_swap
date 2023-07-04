/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalketbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:12:45 by oalketbi          #+#    #+#             */
/*   Updated: 2022/02/21 11:51:53 by oalketbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include "./get_next_line/get_next_line.h"

static void	ft_two(t_list **a, t_list **b, void (*p)(t_list **, char *))
{
	p(a, "");
	p(b, "");
}

static void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static	void	ft_sort_check2(t_list **stack_a, t_list **stack_b, char *s)
{
	if (!ft_strncmp(s, "sa", ft_strlen(s) - 1))
		ft_swap(stack_a, "");
	else if (!ft_strncmp(s, "sb", ft_strlen(s) - 1))
		ft_swap(stack_b, "");
	else if (!ft_strncmp(s, "ra", ft_strlen(s) - 1))
		ft_r(stack_a, "");
	else if (!ft_strncmp(s, "rb", ft_strlen(s) - 1))
		ft_r(stack_b, "");
	else if (!ft_strncmp(s, "pa", ft_strlen(s) - 1))
		ft_push(stack_b, stack_a, "");
	else if (!ft_strncmp(s, "pb", ft_strlen(s) - 1))
		ft_push(stack_a, stack_b, "");
	else if (!ft_strncmp(s, "rr", ft_strlen(s) - 1))
		ft_two(stack_a, stack_b, ft_r);
	else if (!ft_strncmp(s, "rra", ft_strlen(s) - 1))
		ft_rr(stack_a, "");
	else if (!ft_strncmp(s, "rrb", ft_strlen(s) - 1))
		ft_rr(stack_b, "");
	else if (!ft_strncmp(s, "rrr", ft_strlen(s) - 1))
		ft_two(stack_a, stack_b, ft_rr);
	else if (!ft_strncmp(s, "ss", ft_strlen(s) - 1))
		ft_two(stack_a, stack_b, ft_swap);
	else
		ft_exit();
}

static	void	ft_sort_check(t_list **stack_a, t_list **stack_b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		ft_sort_check2(stack_a, stack_b, s);
		free(s);
		s = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_createlist(argc, argv);
	if (!stack_a)
		exit (0);
	else
	{
		ft_sort_check(&stack_a, &stack_b);
		if (!ft_sorted(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_stack_delet(&stack_a);
	return (0);
}
