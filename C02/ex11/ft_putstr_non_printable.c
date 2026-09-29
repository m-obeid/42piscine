/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 13:40:13 by mobeid            #+#    #+#             */
/*   Updated: 2026/09/29 16:23:33 by mobeid           ###   ########.fr       */
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
	while (*str != '\0')
	{
		if (*str <= 31)
			ft_putnpchar(*str);
		else
			write(1, str, 1);
		str++;
	}
}

/* int main(int argc, char const *argv[])
{
	char	str[] = "Hello\xAB World!";
	ft_putstr_non_printable(str);
	return 0;
} */
