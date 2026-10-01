/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 14:18:06 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/01 18:38:38 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putbyte16(unsigned char byte, int i, unsigned int maxsize)
{
	char	*digits;

	digits = "0123456789abcdef";
	if ((unsigned int)i < maxsize)
	{
		write(1, &digits[byte / 16], 1);
		write(1, &digits[byte % 16], 1);
	}
	else
		write(1, "  ", 2);
}

void	ft_putaddr16(unsigned long long addr)
{
	char	*digits;
	char	buffer[16];
	int		i;

	digits = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buffer[i] = digits[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, buffer, 16);
	write(1, ": ", 2);
}

void	ft_putchar(char c)
{
	if (c <= 31)
		write(1, ".", 1);
	else
		write(1, &c, 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	g;	
	int				i;

	g = 0;
	ptr = (unsigned char *)addr;
	while (g < size)
	{
		ft_putaddr16((unsigned long long)ptr);
		i = 0;
		while (i < 16)
		{
			ft_putbyte16(ptr[i], i, size - g);
			ft_putbyte16(ptr[i + 1], i + 1, size - g);
			write(1, " ", 1);
			i += 2;
		}
		i = -1;
		while (++i < 16 && (unsigned int)i < size - g)
			ft_putchar(ptr[i]);
		write(1, "\n", 1);
		g += 16;
		ptr += 16;
	}
	return (addr);
}

/* int	main(void)
{
	char	*test;

	test = "Hello World!";
	ft_print_memory(test, 13);
	return (0);
} */
