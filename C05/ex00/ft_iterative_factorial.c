/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 17:07:29 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/06 17:24:11 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	n;

	i = 1;
	n = i;
	if (nb == 0)
		return (1);
	while (i != nb)
	{
		i++;
		n *= i;
	}
	return (n);
}

/* int	main(void)
{
	printf("%d", ft_iterative_factorial(0));
	return (0);
} */
