/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:00:54 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/05 12:43:55 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	res;
	int	neg;

	res = 0;
	neg = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -neg;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}

/* int main(void)
{
	char	a[] = "---+--+1234ab567";
	int	i;

	i = ft_atoi(a);
	printf("%d", i);
	return (0);
} */
