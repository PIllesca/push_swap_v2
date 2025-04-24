/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:59:26 by pillesca          #+#    #+#             */
/*   Updated: 2025/04/24 19:08:09 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * This function applies the standard rotation to the stacks and pushes from
 * stack a to stack b
 * 
 * @param[in] s_a Reference to stack a
 * @param[in] s_b Reference to stack b
 * @param[in] move Move to do
 */
void	ft_apply_rarb(t_stack **s_a, t_stack **s_b, t_move move)
{
	if (move.destination == b_stack)
	{
		while ((*s_a)->nb != move.nb && ft_find_new_b(*s_b, move.nb) > 0)
			ft_rr(s_a, s_b);
		while ((*s_a)->nb != move.nb)
			ft_ra(s_a);
		while (ft_find_new_b(*s_b, move.nb) > 0)
			ft_rb(s_b);
		ft_pb(s_a, s_b);
	}
	else
	{
		while ((*s_b)->nb != move.nb && ft_find_new_a(*s_a, move.nb) > 0)
			ft_rr(s_a, s_b);
		while ((*s_b)->nb != move.nb)
			ft_rb(s_b);
		while (ft_find_new_a(*s_a, move.nb) > 0)
			ft_ra(s_a);
		ft_pa(s_a, s_b);
	}
}

/**
 * This function applies the reverse rotation to the stacks and pushes from
 * stack a to stack b
 * 
 * @param[in] s_a Reference to stack a
 * @param[in] s_b Reference to stack b
 * @param[in] move Move to do
 */
void	ft_apply_rrarrb(t_stack **s_a, t_stack **s_b, t_move move)
{
	if (move.destination == b_stack)
	{
		while ((*s_a)->nb != move.nb && ft_find_new_b(*s_b, move.nb) > 0)
			ft_rrr(s_a, s_b);
		while ((*s_a)->nb != move.nb)
			ft_rra(s_a);
		while (ft_find_new_b(*s_b, move.nb) > 0)
			ft_rrb(s_b);
		ft_pb(s_a, s_b);
	}
	else
	{
		while ((*s_b)->nb != move.nb && ft_find_new_a(*s_a, move.nb) > 0)
			ft_rrr(s_a, s_b);
		while ((*s_b)->nb != move.nb)
			ft_rrb(s_b);
		while (ft_find_new_a(*s_a, move.nb) > 0)
			ft_rra(s_a);
		ft_pa(s_a, s_b);
	}
}

/**
 * This function applies the standard rotation to the stack a, the reverse
 * rotation to stack b and pushes from stack a to stack b
 * 
 * @param[in] s_a Reference to stack a
 * @param[in] s_b Reference to stack b
 * @param[in] move Move to do
 */
void	ft_apply_rrarb(t_stack **s_a, t_stack **s_b, t_move move)
{
	if (move.destination == b_stack)
	{
		while ((*s_a)->nb != move.nb)
			ft_rra(s_a);
		while (ft_find_new_b(*s_b, move.nb) > 0)
			ft_rb(s_b);
		ft_pb(s_a, s_b);
	}
	else
	{
		while ((*s_b)->nb != move.nb)
			ft_rb(s_b);
		while (ft_find_new_a(*s_a, move.nb) > 0)
			ft_rra(s_a);
		ft_pa(s_a, s_b);
	}
}

/**
 * This function applies the reverse rotation to stack a, the standard
 * rotation to stack b and pushes from stack a to stack b
 * 
 * @param[in] s_a Reference to stack a
 * @param[in] s_b Reference to stack b
 * @param[in] move Move to do
 */
void	ft_apply_rarrb(t_stack **s_a, t_stack **s_b, t_move move)
{
	if (move.destination == b_stack)
	{
		while ((*s_a)->nb != move.nb)
			ft_ra(s_a);
		while (ft_find_new_b(*s_b, move.nb) > 0)
			ft_rrb(s_b);
		ft_pb(s_a, s_b);
	}
	else
	{
		while ((*s_b)->nb != move.nb)
			ft_rrb(s_b);
		while (ft_find_new_a(*s_a, move.nb) > 0)
			ft_ra(s_a);
		ft_pa(s_a, s_b);
	}
}
