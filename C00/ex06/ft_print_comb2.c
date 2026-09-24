/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 18:28:34 by mobeid            #+#    #+#             */
/*   Updated: 2026/09/24 20:24:31 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comma(void)
{
	write(1, ", ", 2);
}

void	ft_print_digits(int a)
{
	char	ca;
	char	cb;
	char	cc;
	char	cd;

	ca = '0' + (a / 1000) % 10;
	cb = '0' + (a / 100) % 10;
	cc = '0' + (a / 10) % 10;
	cd = '0' + (a) % 10;
	write(1, &ca, 1);
	write(1, &cb, 1);
	write(1, " ", 1);
	write(1, &cc, 1);
	write(1, &cd, 1);
	if (a != 9999)
	{
		ft_print_comma();
	}
}

void	ft_print_comb2(void)
{
	int	a;

	a = 1;
	while (a <= 9999)
	{
		ft_print_digits(a);
		a++;
	}
}

/* int	main(void)
{
	ft_print_comb2();
	return (0);
} */
