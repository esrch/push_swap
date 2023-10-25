/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:29:07 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:29:09 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_push(t_stack *stack, int new_elem)
{
	stack_update_min_max(stack, new_elem);
	stack_shift_right(stack);
	stack->elements[0] = new_elem;
	stack->content_size++;
}

int	stack_pop(t_stack *stack)
{
	int	elem;

	elem = stack->elements[0];
	stack_shift_left(stack);
	stack->content_size--;
	return (elem);
}

void	stack_push_end(t_stack *stack, int elem)
{
	stack_update_min_max(stack, elem);
	stack->elements[stack->content_size] = elem;
	stack->content_size++;
}
