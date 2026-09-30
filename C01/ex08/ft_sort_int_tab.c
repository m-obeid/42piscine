/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:28:34 by mobeid            #+#    #+#             */
/*   Updated: 2026/09/30 13:55:47 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/* int main(int argc, char const *argv[])
{
	int	digits[] = { 4, 2, 9, 8, 7, 6 };
	int	i;

	ft_sort_int_tab(digits, 6);
	i = 0;
	while (i < 6)
	{
		printf("%d,", digits[i]);
		i++;
	}
	return 0;
} */
