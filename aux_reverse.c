/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:28:04 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 17:23:22 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Rotates a stack in reverse
 * 
 * @param[in] stack Stack to rotate
*/
void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
}

/**
 * Rotates stack a in reverse
 * 
 * @param[in] stack Stack to rotate
*/
void	ft_rra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	ft_reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

/**
 * Rotates stack b in reverse
 * 
 * @param[in] stack Stack to rotate
*/
void	ft_rrb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	ft_reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

/**
 * Rotates both stacks in reverse
 * 
 * @param[in] stack_a Reference to stack a
 * @param[in] stack_b Reference to stack b
*/
void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next
		|| !stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
