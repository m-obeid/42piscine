/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 13:41:08 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/07 14:23:02 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 46340 is the last number squared that fits inside INT_MAX
// Going higher will cause overflow, so we stop there
int	ft_sqrt(int nb)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	if (nb < 0)
		return (0);
	while (r < nb && i <= 46340)
	{
		r = i * i;
		if (r == nb)
			return (i);
		i++;
	}
	return (0);
}

/* int	main(void)
{
	printf("%d", ft_sqrt(64));
} */
