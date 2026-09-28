/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:28:34 by mobeid            #+#    #+#             */
/*   Updated: 2026/09/28 17:47:38 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

/* int main(int argc, char const *argv[])
{
	int	digits[] = { 4, 2, 9, 8, 7, 6 };
	int	i;

	ft_rev_int_tab(digits, 6);
	i = 0;
	while (i < 6)
	{
		printf("%d,", digits[i]);
		i++;
	}
	return 0;
} */
