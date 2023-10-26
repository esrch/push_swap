/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:29:15 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/26 12:05:07 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_init(int total_size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->elements = malloc(sizeof(int) * total_size);
	if (!stack->elements)
	{
		stack_free(stack);
		return (NULL);
	}
	stack->content_size = 0;
	stack->total_size = total_size;
	return (stack);
}

void	stack_free(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack->elements);
	free(stack);
}

bool	stack_contains(t_stack *stack, int elem)
{
	int	i;

	i = 0;
	while (i < stack->content_size)
	{
		if (stack->elements[i] == elem)
			return (true);
		i++;
	}
	return (false);
}

bool	stack_is_sorted(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->content_size)
	{
		if (stack->elements[i] <= stack->elements[i - 1])
			return (false);
		i++;
	}
	return (true);
}

bool	stack_is_sorted_rotated(t_stack *stack)
{
	int		i;
	bool	passed_min_max_split;

	if (stack->content_size < 3)
		return (true);
	i = 1;
	passed_min_max_split = false;
	while (i < stack->content_size)
	{
		if (stack->elements[i] <= stack->elements[i - 1])
		{
			if (passed_min_max_split)
				return (false);
			else
				passed_min_max_split = true;
		}
		i++;
	}
	if (stack->elements[0] <= stack->elements[stack->content_size - 1])
		return (false);
	return (true);
}
