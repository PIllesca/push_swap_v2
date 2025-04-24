/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:42:59 by pillesca          #+#    #+#             */
/*   Updated: 2025/04/24 18:42:28 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * This funcition finds the index of the number if it was in the stack
 * 
 * @param[in] s_b Stack to search
 * @param[in] nb Number to search
 * @returns The index if the number was in the stack
 */
int	ft_find_new_b(t_stack *s_b, int nb)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nb > s_b->nb && nb < ft_find_last(s_b)->nb)
		i = 0;
	else if (nb < ft_find_min(s_b) || nb > ft_find_max(s_b))
		i = ft_find_index(s_b, ft_find_max(s_b));
	else
	{
		tmp = s_b->next;
		while (s_b->nb < nb || tmp->nb > nb)
		{
			s_b = s_b->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

/**
 * This funcition finds the index of the number if it was in the stack
 * 
 * @param[in] s_a Stack to search
 * @param[in] nb Number to search
 * @returns The index if the number was in the stack
 */
int	ft_find_new_a(t_stack *s_a, int nb)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nb < s_a->nb && nb > ft_find_last(s_a)->nb)
		i = 0;
	else if (nb < ft_find_min(s_a) || nb > ft_find_max(s_a))
		i = ft_find_index(s_a, ft_find_min(s_a));
	else
	{
		tmp = s_a->next;
		while (s_a->nb > nb || tmp->nb < nb)
		{
			s_a = s_a->next;
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

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
