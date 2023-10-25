/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:29:32 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:29:33 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_index_distance_to_top(t_stack *stack, int index)
{
	if (index < stack->content_size - index)
		return (index);
	else
		return (index - stack->content_size);
}

void	stack_update_min_max(t_stack *stack, int elem)
{
	if (stack->content_size == 0 || elem > stack->max)
		stack->max = elem;
	if (stack->content_size == 0 || elem < stack->min)
		stack->min = elem;
}

void	stack_shift_left(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->content_size - 1)
	{
		stack->elements[i] = stack->elements[i + 1];
		i++;
	}
}

void	stack_shift_right(t_stack *stack)
{
	int	i;

	i = stack->content_size;
	while (i)
	{
		stack->elements[i] = stack->elements[i - 1];
		i--;
	}
}
