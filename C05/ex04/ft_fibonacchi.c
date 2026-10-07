/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacchi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 13:24:11 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/07 13:41:41 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int	n1;
	int	n2;
	int	fib;

	n1 = 0;
	n2 = 1;
	fib = 0;
	index -= 2;
	while (index >= 0)
	{
		fib = n1 + n2;
		n1 = n2;
		n2 = fib;
		index--;
	}
	return (fib);
}

/* int	main(void)
{
	printf("%d", ft_fibonacci(10));
} */
