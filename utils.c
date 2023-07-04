/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalketbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:16:30 by oalketbi          #+#    #+#             */
/*   Updated: 2022/02/21 11:53:06 by oalketbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_set(int argc, char **argv, int *i)
{
	char	**temp;
	int		x;

	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		*i = 0;
		while (temp[*i])
			(*i)++;
	}
	else
	{
		temp = (char **) malloc(sizeof(char *) * (argc));
		temp[argc - 1] = 0;
		x = 0;
		while (++x < argc)
		{
			temp[x - 1] = ft_strdup(argv[x]);
		}
		*i = argc - 1;
	}
	return (temp);
}

void	ft_stack_delet(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp->content);
		free(temp);
	}
}

t_list	*ft_createlist(int argc, char **argv)
{
	int		x;
	t_list	*head;
	t_list	*ptr;
	char	**num;
	int		i;

	head = NULL;
	num = ft_set(argc, argv, &i);
	ft_check_input(num);
	x = 0;
	while (x < i)
	{
		if (head == NULL)
		{
			head = ft_lstnew(num[x]);
			ptr = head;
		}
		else
			ft_lstadd_back(&ptr, ft_lstnew(num[x]));
		x++;
	}
	free (num);
	return (head);
}

long	ft_atol(const char *str)
{
	int		i;
	int		n;
	long	num;

	if (!str)
		return (0);
	i = 0;
	n = 1;
	num = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - '0');
	return (num * n);
}

int	ft_sorted(t_list *stack)
{
	while (stack->next)
	{
		if (ft_atoi(stack->content) > ft_atoi(stack->next->content))
			return (1);
		stack = stack->next;
	}
	return (0);
}
