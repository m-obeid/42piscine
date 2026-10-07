/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:24:39 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/07 13:22:45 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	basenum;

	i = 0;
	basenum = nb;
	if (power == 0)
		return (1);
	while (i < power - 1)
	{
		nb *= basenum;
		i++;
	}
	return (nb);
}

/* int main(void)
{
	printf("%d", ft_iterative_power(0, 0));
	return (0);
} */
