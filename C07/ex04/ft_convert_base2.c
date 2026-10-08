/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:06:35 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/08 11:27:51 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Some helper functions live in here, as Norme limits prevent me from having 
// that many functions in one file

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_find_dval(char *base, char c)
{
	int	j;

	j = 0;
	while (base[j] != '\0')
	{
		if (base[j] == c)
			return (j);
		j++;
	}
	return (-1);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_find_res(int *res, char *base, int baselen, char *str)
{
	int	dval;

	*res = 0;
	while (*str != '\0')
	{
		dval = ft_find_dval(base, *str);
		if (dval == -1)
			break ;
		*res = (*res * baselen) + dval;
		str++;
	}
}

int	ft_atoi_base(char *str, char *base, int *out)
{
	int	neg;
	int	baselen;
	int	res;

	baselen = ft_check_base(base);
	if (baselen < 2)
		return (0);
	neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -neg;
		str++;
	}
	ft_find_res(&res, base, baselen, str);
	*out = (res * neg);
	return (1);
}
