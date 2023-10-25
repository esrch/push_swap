/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:29:02 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:29:03 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_swap(t_stack *stack)
{
	int	tmp;

	if (stack->content_size < 2)
		return ;
	tmp = stack->elements[0];
	stack->elements[0] = stack->elements[1];
	stack->elements[1] = tmp;
}

void	stack_rotate(t_stack *stack, int times)
{
	int	i;
	int	first_elem;

	if (stack->content_size < 2)
		return ;
	i = 0;
	while (i < times)
	{
		first_elem = stack->elements[0];
		stack_shift_left(stack);
		stack->elements[stack->content_size - 1] = first_elem;
		i++;
	}
}

void	stack_rev_rotate(t_stack *stack, int times)
{
	int	i;
	int	last_elem;

	if (stack->content_size < 2)
		return ;
	i = 0;
	while (i < times)
	{
		last_elem = stack->elements[stack->content_size - 1];
		stack_shift_right(stack);
		stack->elements[0] = last_elem;
		i++;
	}
}
