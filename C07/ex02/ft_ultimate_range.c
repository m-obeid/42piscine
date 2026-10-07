/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:28:00 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/07 18:08:45 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc((max - min) * sizeof(int));
	i = 0;
	while (i + min < max)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (max - min);
}

int	main(void)
{
	int	*range;
	int	size;
	int	i;

	size = ft_ultimate_range(&range, 0, 10);
	if (range == NULL)
		return (1);
	i = 0;
	while (i < size)
	{
		printf("%d size:%d\n", range[i], size);
		i++;
	}
	free(range);
	return (0);
}
