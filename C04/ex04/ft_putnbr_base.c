/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:27:13 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/05 12:43:53 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i - 1;
		while (j != -1 && j >= 0)
		{
			if (base[j] == base[i])
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	long	baselen;
	long	nbr;

	baselen = ft_strlen(base);
	if (baselen <= 1 || ft_check_base(base) == 0)
		return ;
	nbr = nb;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 0 && nbr < baselen)
	{
		ft_putchar(base[nb]);
	}
	else
	{
		ft_putnbr_base(nbr / baselen, base);
		ft_putnbr_base(nbr % baselen, base);
	}
}

/* int main(void)
{
	int	dec = 42;
	ft_putnbr_base(dec, "0123456789ABCDEF"); // 2A
} */
