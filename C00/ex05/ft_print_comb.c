/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 14:24:09 by mobeid            #+#    #+#             */
/*   Updated: 2026/09/24 18:18:59 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comma(void)
{
	write(1, ", ", 2);
}

void	ft_print_digits(int a, int b, int c)
{
	char	ca;
	char	cb;
	char	cc;

	if (a != 0 || b != 1 || c != 2)
	{
		ft_print_comma();
	}
	ca = '0' + a;
	cb = '0' + b;
	cc = '0' + c;
	write(1, &ca, 1);
	write(1, &cb, 1);
	write(1, &cc, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	while (a <= 7)
	{
		b = a;
		while (b <= 8)
		{
			c = b;
			while (c <= 9)
			{
				if (a != c && a != b && b != c)
				{
					ft_print_digits(a, b, c);
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
