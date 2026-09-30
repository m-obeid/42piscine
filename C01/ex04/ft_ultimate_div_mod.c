/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:07:48 by mobeid            #+#    #+#             */
/*   Updated: 2026/09/30 12:10:43 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a % *b;
	*a = div;
	*b = mod;
}

/* int main(int argc, char const *argv[])
{
	int	a;
	int	b;

	a = 25;
	b = 7;
	ft_ultimate_div_mod(&a, &b);

	printf("%dR%d", a, b);
	return (0);
} */
