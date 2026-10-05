/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 13:40:13 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/01 16:20:08 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnpchar(char c)
{
	char			*digits;
	unsigned char	uc;
	char			d1;
	char			d2;

	digits = "0123456789abcdef";
	uc = (unsigned char)c;
	d1 = digits[uc / 16];
	d2 = digits[uc % 16];
	write(1, "\\", 1);
	write(1, &d1, 1);
	write(1, &d2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31)
			ft_putnpchar(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}

/* int main(int argc, char const *argv[])
{
	char	str[] = "Hello\xAB World!";
	ft_putstr_non_printable(str);
	return 0;
} */
