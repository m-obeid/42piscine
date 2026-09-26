/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 09:57:48 by mobeid            #+#    #+#             */
/*   Updated: 2026/09/25 12:37:54 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_digits(int a, int nc)
{
	char	c;

	if (nc > 1)
		ft_print_digits(a / 10, nc - 1);
	c = '0' + (a % 10);
	write(1, &c, 1);
}

int	ft_isasc(int a, int n)
{
	int	prev;
	int	cur;

	prev = 10;
	while (n > 0)
	{
		cur = a % 10;
		if (cur >= prev)
			return (0);
		prev = cur;
		a /= 10;
		n--;
	}
	return (1);
}

int	ft_max(int n)
{
	int	max;
	int	i;

	max = 0;
	i = 10 - n;
	while (i <= 9)
	{
		max = (max * 10) + i;
		i++;
	}
	return (max);
}

void	ft_print_combn(int n)
{
	int	max;
	int	a;
	int	i;

	max = ft_max(n);
	a = 0;
	i = 0;
	while (i < n)
	{
		a = a * 10 + i;
		i++;
	}
	ft_print_digits(a, n);
	a++;
	while (a <= max)
	{
		if (ft_isasc(a, n) == 1)
		{
			write(1, ", ", 2);
			ft_print_digits(a, n);
		}
		a++;
	}
}

int	main(void)
{
	ft_print_combn(2);
	return (0);
}
