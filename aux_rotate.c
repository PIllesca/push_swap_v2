/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:20:52 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 17:21:56 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Rotates a stack
 * 
 * @param[in] stack Stack to rotate
*/
static void	ft_rotate_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	last = tmp;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

/**
 * Rotates stack a
 * 
 * @param[in] stack_a Reference to stack a
*/
void	ft_ra(t_stack **stack_a)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	ft_rotate_stack(stack_a);
	ft_putendl_fd("ra", 1);
}

/**
 * Rotates stack b
 * 
 * @param[in] stack_b Reference to stack b
*/
void	ft_rb(t_stack **stack_b)
{
	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	ft_rotate_stack(stack_b);
	ft_putendl_fd("rb", 1);
}

/**
 * Rotates both stacks
 * 
 * @param[in] stack_a Reference to stack a
 * @param[in] stack_b Reference to stack b

*/
void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !(*stack_a) || !(*stack_a)->next
		|| !stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	ft_rotate_stack(stack_a);
	ft_rotate_stack(stack_b);
	ft_putendl_fd("rr", 1);
}
