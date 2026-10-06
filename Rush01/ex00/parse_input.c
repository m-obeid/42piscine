/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 15:52:21 by ahalawi           #+#    #+#             */
/*   Updated: 2026/10/04 13:00:00 by ahalawi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_space(int count, char *str, int i)
{
	if (count < 15 && str[i] != ' ')
		return (0);
	if (count == 15 && str[i] != '\0')
		return (0);
	return (1);
}

int	parse_input(char *str, int clues[16])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (count < 16)
	{
		if (str[i] < '1' || str[i] > '4')
			return (0);
		clues[count] = str[i] - '0';
		i++;
		if (check_space(count, str, i) == 0)
			return (0);
		if (count < 15)
			i++;
		count++;
	}
	return (1);
}
