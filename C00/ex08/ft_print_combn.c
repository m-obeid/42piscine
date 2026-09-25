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

void	ft_print_comma(void)
{
	write(1, ", ", 2);
}

int	ft_exp(int big, int lit)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	while (i < lit)
	{
		res *= big;
		i++;
	}
	return (res);
}

void	ft_print_digits(int a, int nc)
{
	char	c;
	int		exp;

	exp = ft_exp(10, nc - 1);
	while (exp >= 1)
	{
		c = '0' + (a / exp) % 10;
		write(1, &c, 1);
		exp /= 10;
	}
}

void	ft_print_combn(int n)
{
	int	max;
	int	a;
	int	o;

	max = ft_exp(10, n) - 1;
	a = 1;
	o = 1;
	while (a <= max)
	{
		if (a != 1)
			ft_print_comma();
		ft_print_digits(a, n);
		if (a % 10 == 9)
		{
			o++;
			a += o;
		}
		a++;
	}
}

/* int	main(void)
{
	ft_print_combn(2);
	return (0);
} */
