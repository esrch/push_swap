/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:29:22 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:29:23 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_last(t_stack *stack)
{
	return (stack->elements[stack->content_size - 1]);
}

int	stack_next_index(t_stack *stack, int index)
{
	return ((index + 1) % stack->content_size);
}

int	stack_find_index(t_stack *stack, int elem, bool *is_found)
{
	int	i;

	i = 0;
	while (i < stack->content_size)
	{
		if (stack->elements[i] == elem)
		{
			*is_found = true;
			return (i);
		}
		i++;
	}
	*is_found = false;
	return (0);
}

int	stack_find_min_index(t_stack *stack)
{
	int	i;
	int	min;
	int	min_index;

	if (stack->content_size == 0)
		return (0);
	i = 1;
	min_index = 0;
	min = stack->elements[0];
	while (i < stack->content_size)
	{
		if (stack->elements[i] < min)
		{
			min = stack->elements[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	stack_find_max_index(t_stack *stack)
{
	int	i;
	int	max;
	int	max_index;

	if (stack->content_size == 0)
		return (0);
	i = 1;
	max_index = 0;
	max = stack->elements[0];
	while (i < stack->content_size)
	{
		if (stack->elements[i] > max)
		{
			max = stack->elements[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}
