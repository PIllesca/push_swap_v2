/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:53:40 by pillesca          #+#    #+#             */
/*   Updated: 2024/05/09 14:07:04 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Finds the last element of a stack
 * 
 * @param[in] stack Stack to search
*/
t_stack	*ft_find_last(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/**
 * Finds the smallest number in a stack
 * 
 * @param[in] stack Stack to search
 * @returns Smallest number in stack
*/
int	ft_find_min(t_stack *stack)
{
	int	min;

	min = stack->nb;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

/**
 * Finds the biggest number in a stack
 * 
 * @param[in] stack Stack to search
 * @returns Biggest number in stack

*/
int	ft_find_max(t_stack *stack)
{
	int	max;

	max = stack->nb;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	return (max);
}

/**
 * Finds the index of nb in stack
 * 
 * @param[in] stack Stack to search
 * @param[in] nb Number to search
 * @returns Index of nb in stack
*/
int	ft_find_index(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	while (stack->nb != nb)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
