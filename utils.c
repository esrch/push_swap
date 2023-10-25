/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erabbath <erabbath@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:27:00 by erabbath          #+#    #+#             */
/*   Updated: 2023/10/24 18:27:01 by erabbath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_arg(char *num_str, bool *is_valid_num)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	*is_valid_num = true;
	if (*num_str == '-')
		sign = -1;
	if (*num_str == '-' || *num_str == '+')
		num_str++;
	while (*num_str && *is_valid_num)
	{
		if (*num_str < '0' || *num_str > '9')
			*is_valid_num = false;
		result = result * 10 + (*num_str - '0');
		if (result > (long) INT_MAX + 1)
			*is_valid_num = false;
		num_str++;
	}
	result *= sign;
	if (result > (long) INT_MAX || result < (long) INT_MIN)
		*is_valid_num = false;
	if (!*is_valid_num)
		return (0);
	return ((int) result);
}

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
}

void	print_mult(char *str, size_t times)
{
	size_t	i;

	i = 0;
	while (i < times)
	{
		ft_putendl_fd(str, 1);
		i++;
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
