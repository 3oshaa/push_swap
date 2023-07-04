/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalketbi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:32:17 by oalketbi          #+#    #+#             */
/*   Updated: 2022/02/08 14:32:22 by oalketbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>

int		ft_sort_three(t_list **stack);
void	ft_sort_five(t_list **stack_a, t_list **stack_b, int *sorted_arr);
void	ft_push_to_a(t_list **a, t_list **b, int *sorted_arr, int len);
void	ft_push_to_b(t_list **a, t_list **b, int *sorted_arr, int len);
void	ft_swap(t_list **stack, char *str);
void	ft_r(t_list **stack, char *str);
void	ft_rr(t_list **stack, char *str);
void	ft_push(t_list **stack1, t_list **stack2, char *str);
void	ft_error_message(char **num);
void	ft_check_input(char **input);
t_list	*ft_createlist(int i, char **num);
int		ft_sorted(t_list *stack);
int		ft_sorted_arr(int *arr, int size);
void	ft_sort_stack(t_list *stack, int *arr);
int		ft_has_value(t_list *stack, int value, int value2);
void	*ft_sort(t_list **stack_a, t_list **stack_b);
void	ft_update_limit(int *lower_limit, int *higher_limit, int len, int i);
long	ft_atol(const char *str);
void	ft_stack_delet(t_list **stack);
char	**ft_set(int argc, char **argv, int *i);
#endif
