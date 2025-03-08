/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:16:29 by pillesca          #+#    #+#             */
/*   Updated: 2025/03/08 12:59:25 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/**
 * Contains the stack and stack size
 * 
 * @param array Int with the content of this element of the stack
 * @param s_stack Next element in the stack
*/
typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}	t_stack;

/**
 * Enum that points which stack to push to
 */
typedef enum e_dest
{
	a_stack,
	b_stack
}	t_dest;

/**
 * Enum that selects with rotation to use before the push
 */
typedef enum e_rot
{
	rarb,
	rrarrb,
	rrarb,
	rarrb
}	t_rot;

/**
 * Contains the information needed to push a number to another stack
 * 
 * @param destination Enum that points which stack to push to
 * @param rotation Enum that selects with rotation to use before the push
 * @param c	How many rotations it will take to prepare the stack for the push
 * @param nb The number we will push to the other stack
*/
typedef struct s_move
{
	t_dest	destination;
	t_rot	rotation;
	int		c;
	int		nb;
}	t_move;

void	ft_chk_args(int argc, char *argv[]);
void	ft_error_exit(t_stack *s_a);
void	ft_free_str(char **str);
void	ft_free_stack(t_stack *s_a);
t_stack	*ft_init_stack(int argc, char *argv[]);
void	ft_push_swap(int argc, char *argv[]);
int		ft_chk_sorted(t_stack *stack);
void	ft_sa(t_stack **s_a);
void	ft_sb(t_stack **s_b);
void	ft_ss(t_stack **s_a, t_stack **s_b);
void	ft_ra(t_stack **stack);
void	ft_rb(t_stack **stack);
void	ft_rr(t_stack **s_a, t_stack **s_b);
void	ft_rra(t_stack **stack);
void	ft_rrb(t_stack **stack);
void	ft_rrr(t_stack **s_a, t_stack **s_b);
void	ft_pa(t_stack **s_a, t_stack **s_b);
void	ft_pb(t_stack **s_a, t_stack **s_b);
int		ft_stack_size(t_stack *stack);
void	ft_sort_three(t_stack **stack);
t_stack	*ft_find_last(t_stack *stack);
int		ft_find_min(t_stack *stack);
int		ft_find_max(t_stack *stack);
int		ft_find_index(t_stack *stack, int nb);

#endif