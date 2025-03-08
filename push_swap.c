/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:02:38 by pillesca          #+#    #+#             */
/*   Updated: 2025/03/08 13:01:51 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * This functions pushes the already sorted numbers from stack b to stack a
*/
static void	ft_pop_sort(t_stack **s_a, t_stack **s_b)
{
}

/**
 * This function sorts as it pushes the numbers from stack a to stack b until
 * there are only 3 numbers left in stack a or stack a is sorted
 * 
 * @param[in] s_a Reference to stack a
 * @param[in] s_b Reference to stack b
*/
static void	ft_push_sort(t_stack **s_a, t_stack **s_b)
{
}

/**
 * This function rotates stack a to the correct position after sorting if it
 * isn't in the correct position.
 * 
 * @param[in] s_a Reference to stack a
*/
static void	ft_rotate_sort(t_stack **s_a)
{
	int	min;
	int	index;

	if (!ft_chk_sorted(*s_a))
	{
		min = ft_find_min(*s_a);
		index = ft_find_index(*s_a, min);
		if (index < ft_stack_size(*s_a) - index)
			while ((*s_a)->nb != min)
				ft_ra(s_a);
		else
			while ((*s_a)->nb != min)
				ft_rra(s_a);
	}
}

/**
 * This functions uses stack b to sort stack a. If it has 2 elements it swaps
 * them, if it has more than 3 elements it pushes the elements and sorts them
 * in stack b, if stack a has 3 unsroted elements it sorts them. Finally it
 * pushes the sorted elements from stack b to stack a.
*/
static void	ft_sort_stack(t_stack **s_a, t_stack **s_b)
{
	if (ft_stack_size(*s_a) == 2)
		ft_sa(s_a);
	else
	{
		if (ft_stack_size(*s_a) > 3 && !ft_chk_sorted(*s_a))
			ft_pb(s_a, s_b);
		if (ft_stack_size(*s_a) > 3 && !ft_chk_sorted(*s_a))
			ft_pb(s_a, s_b);
		if (ft_stack_size(*s_a) > 3 && !ft_chk_sorted(*s_a))
			ft_push_sort(s_a, s_b);
		if (ft_stack_size(*s_a) == 3 && !ft_chk_sorted(*s_a))
			ft_sort_three(s_a);
	}
	ft_pop_sort(s_a, s_b);
	ft_rotate_sort(s_a);
}

/**
 * Main function. Initiates stack a with the executable input and checks if it
 * is already sorted. If it isn't sorted calls the function ft_sort_stack to
 * sort the stack.
 * 
 * @param[in] argc Number of arguments
 * @param[in] argv String array input
 * @param[in] c Size of the stacks
*/
void	ft_push_swap(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = ft_init_stack(argc, argv);
	stack_b = NULL;
	if (!ft_chk_sorted(stack_a))
		ft_sort_stack(&stack_a, &stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
