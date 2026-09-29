/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:14:57 by mobeid            #+#    #+#             */
/*   Updated: 2026/09/29 12:32:38 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str <= 31)
			return (0);
		str++;
	}
	return (1);
}

/* int main(int argc, char const *argv[])
{
	char	str[] = "abc123##\t\n";
	return (ft_str_is_printable(str));
} */
