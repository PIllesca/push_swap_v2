/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:42:59 by pillesca          #+#    #+#             */
/*   Updated: 2025/03/08 12:43:12 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Sorts a stack of 3 elements
 * 
 * @param[in] stack Stack to sort
*/
void	ft_sort_three(t_stack **stack)
{
	if ((*stack)->nb == ft_find_min(*stack))
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if ((*stack)->nb == ft_find_max(*stack))
	{
		ft_ra(stack);
		if (!ft_chk_sorted((*stack)))
			ft_sa(stack);
	}
	else
	{
		if (ft_find_index((*stack), ft_find_max(*stack)) == 1)
			ft_rra(stack);
		else
			ft_sa(stack);
	}
}
