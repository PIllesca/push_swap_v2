/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:15:08 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 17:17:49 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Pushes the top element of stack src to stack dst
 * 
 * @param[in] dst Destination stack
 * @param[in] src Source stack
 */
static void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!(*src))
		return ;
	tmp = *src;
	*src = tmp->next;
	tmp->next = *dst;
	*dst = tmp;
}

/**
 * Pushes the top element of stack a to stack b
 * 
 * @param[in] s_a Stack a
 * @param[in] s_b Stack b
 */
void	ft_pa(t_stack **s_a, t_stack **s_b)
{
	ft_push(s_b, s_a);
	ft_putendl_fd("pa", 1);
}

/**
 * Pushes the top element of stack b to stack a
 * 
 * @param[in] s_a Stack a
 * @param[in] s_b Stack b
 */
void	ft_pb(t_stack **s_a, t_stack **s_b)
{
	ft_push(s_a, s_b);
	ft_putendl_fd("pb", 1);
}

/**
 * Returns the size of the stack
 * 
 * @param[in] stack Stack to measure
 * @returns Size of the stack
 */
int	ft_stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}
