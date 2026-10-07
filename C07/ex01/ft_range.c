/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:28:00 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/07 18:04:57 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	if (min >= max)
		return (NULL);
	range = malloc((max - min) * sizeof(int));
	i = 0;
	while (i + min < max)
	{
		range[i] = i + min;
		i++;
	}
	return (range);
}

/* int	main(void)
{
	int	*range;

	range = ft_range(0, 10);
	if (range == NULL)
		return (1);
	while (*range < 10)
	{
		printf("%d\n", *range);
		range++;
	}
	free(range);
	return (0);
} */
