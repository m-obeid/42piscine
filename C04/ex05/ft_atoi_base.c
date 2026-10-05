/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 12:01:49 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/05 14:04:30 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi_base(char *str, char *base)
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
	return (res * neg);
}

/* int main(void)
{
	char	a[] = "---+--+4D2abcd";
	int	i;

	i = ft_atoi_base(a, "0123456789ABCDEF");
	printf("%d", i);
	return (0);
} */
