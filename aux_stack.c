/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pillesca <pillesca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:04:52 by pillesca          #+#    #+#             */
/*   Updated: 2025/03/08 12:23:33 by pillesca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

/**
 * Frees the memory from a ft_split
 * 
 * @param[in] str String array to free
*/
void	ft_free_str(char **str)
{
	char	**temp;

	temp = str;
	while (*temp != NULL)
	{
		free(*temp);
		temp++;
	}
	free(str);
}

/**
 * Creates a new node for the stack
 * 
 * @param[in] nb Number to store in the node
 * @param[in] s_a Stack to free in case of error
 * @returns New node
*/
static t_stack	*ft_new_node(int nb, t_stack *s_a)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		ft_error_exit(s_a);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

/**
 * Initializes the stack with the input arguments
 * 
 * @param[in] argc Number of arguments
 * @param[in] argv String array input
 * @returns Initialized stack 
*/
t_stack	*ft_init_stack(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		i;
	char	**args;

	i = 1;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 2;
		args = argv;
	}
	stack_a = ft_new_node(ft_atoi(args[i - 1]), NULL);
	tmp = stack_a;
	while (args[i])
	{
		tmp->next = ft_new_node(ft_atoi(args[i]), stack_a);
		tmp = tmp->next;
		i++;
	}
	if (argc == 2)
		ft_free_str(args);
	return (stack_a);
}

/**
 * Frees the memory from a stack
 * 
 * @param[in] s_a Stack to free
*/
void	ft_free_stack(t_stack *s_a)
{
	t_stack	*tmp;

	while (s_a)
	{
		tmp = s_a;
		s_a = s_a->next;
		free(tmp);
	}
}

/**
 * Checks if the stack is sorted
 * 
 * @param[in] stack Stack to check
 * @returns 1 if sorted, 0 if not
*/
int	ft_chk_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
