/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:56:27 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 17:00:48 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Swaps the first two elements of a stack
 * 
 * @param[in] stack Stack to swap
*/
static void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

/**
 * Swaps the first two elements of stack a
 * 
 * @param[in] s_a Stack a
*/
void	ft_sa(t_stack **s_a)
{
	ft_swap(s_a);
	ft_putendl_fd("sa", 1);
}

/**
 * Swaps the first two elements of stack b
 * 
 * @param[in] s_b Stack b
*/
void	ft_sb(t_stack **s_b)
{
	ft_swap(s_b);
	ft_putendl_fd("sb", 1);
}

/**
 * Swaps the first two elements of both stacks
 * 
 * @param[in] s_a Stack a
 * @param[in] s_b Stack b
*/
void	ft_ss(t_stack **s_a, t_stack **s_b)
{
	ft_swap(s_a);
	ft_swap(s_b);
	ft_putendl_fd("ss", 1);
}
