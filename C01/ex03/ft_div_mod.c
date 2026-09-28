/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:07:48 by mobeid            #+#    #+#             */
/*   Updated: 2026/09/28 17:13:41 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/* int main(int argc, char const *argv[])
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 25;
	b = 7;
	ft_div_mod(a, b, &div, &mod);

	printf("%dR%d", div, mod);
	return 0;
} */
