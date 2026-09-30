/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 17:02:22 by mobeid            #+#    #+#             */
/*   Updated: 2026/09/30 12:10:28 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	aval;
	int	bval;

	aval = *a;
	bval = *b;
	*a = bval;
	*b = aval;
}

/* int main(int argc, char const *argv[])
{
	int	a;
	int	b;

	a = 42;
	b = 2026;

	ft_swap(&a, &b);
	printf("%d, %d", a, b);
	return (0);
} */
