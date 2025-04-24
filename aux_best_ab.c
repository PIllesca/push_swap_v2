/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_best.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:40:38 by pillesca          #+#    #+#             */
/*   Updated: 2025/04/24 17:47:11 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * This function finds the best way to push a number from stack a to b using
 * the standard rotation
 * 
 * @param[in] s_a Reference to stack a
 * @param[in] s_b Reference to stack b
 * @returns The best move using the standard rotation
 */
static t_move	ft_ab_rarb(t_stack *s_a, t_stack *s_b, int nb)
{
	t_move	move;

	move.destination = b_stack;
	move.rotation = rarb;
	move.nb = nb;
	move.c = ft_find_new_b(s_b, nb);
	if (move.c < ft_find_index(s_a, nb))
		move.c = ft_find_index(s_a, nb);
	return (move);
}

/**
 * This function finds the best way to push a number from stack a to b using
 * the reverse rotation
 * 
 * @param[in] s_a Reference to stack a
 * @param[in] s_b Reference to stack b
 * @returns The best move using reverse rotation
 */
static t_move	ft_ab_rrarrb(t_stack *s_a, t_stack *s_b, int nb)
{
	t_move	move;

	move.c = 0;
	move.destination = b_stack;
	move.rotation = rrarrb;
	move.nb = nb;
	if (ft_find_new_b(s_b, nb))
		move.c = ft_stack_size(s_b) - ft_find_new_b(s_b, nb);
	if (ft_find_index(s_a, nb)
		&& move.c < (ft_stack_size(s_a) - ft_find_index(s_a, nb)))
		move.c = ft_stack_size(s_a) - ft_find_index(s_a, nb);
	return (move);
}

/**
 * This function finds the best way to push a number from stack a to b using
 * the reverse rotation of stack a and the standard rotation of stack b
 * 
 * @param[in] s_a Reference to stack a
 * @param[in] s_b Reference to stack b
 * @returns The best move using reverse rotation
 */
static t_move	ft_ab_rrarb(t_stack *s_a, t_stack *s_b, int nb)
{
	t_move	move;

	move.c = 0;
	move.destination = b_stack;
	move.rotation = rrarb;
	move.nb = nb;
	if (ft_find_index(s_a, nb))
		move.c = ft_stack_size(s_a) - ft_find_index(s_a, nb);
	move.c = move.c + ft_find_new_b(s_b, nb);
	return (move);
}

static t_move	ft_ab_rarrb(t_stack *s_a, t_stack *s_b, int nb)
{
	t_move	move;

	move.c = 0;
	move.destination = b_stack;
	move.rotation = rarrb;
	move.nb = nb;
	if (ft_find_new_b(s_b, nb))
		move.c = ft_stack_size(s_b) - ft_find_new_b(s_b, nb);
	move.c = move.c + ft_find_index(s_a, nb);
	return (move);
}

/**
 * This function finds the best way to push a number from stack a to stack b
 * 
 * @param[in] s_a Reference to stack a
 * @param[in] s_b Reference to stack b
 * @returns The best move to do
 */
t_move	ft_best_ab_push(t_stack *s_a, t_stack *s_b)
{
	t_move	move;
	t_stack	*tmp;

	tmp = s_a;
	move = ft_ab_rarb(s_a, s_b, s_a->nb);
	while (tmp)
	{
		if (move.c > ft_ab_rarb(s_a, s_b, tmp->nb).c)
			move = ft_ab_rarb(s_a, s_b, tmp->nb);
		if (move.c > ft_ab_rrarrb(s_a, s_b, tmp->nb).c)
			move = ft_ab_rrarrb(s_a, s_b, tmp->nb);
		if (move.c > ft_ab_rrarb(s_a, s_b, tmp->nb).c)
			move = ft_ab_rrarb(s_a, s_b, tmp->nb);
		if (move.c > ft_ab_rarrb(s_a, s_b, tmp->nb).c)
			move = ft_ab_rarrb(s_a, s_b, tmp->nb);
		tmp = tmp->next;
	}
	return (move);
}
