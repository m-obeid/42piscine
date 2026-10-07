/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 18:11:35 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/07 19:03:43 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	dlen;
	unsigned int	i;

	dlen = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dest);
}

long	get_total_size(int size, char **strs, char *sep)
{
	int		i;
	long	final;

	i = 0;
	final = 0;
	while (i < size)
	{
		final += ft_strlen(strs[i]);
		if (i + 1 < size)
			final += ft_strlen(sep);
		i++;
	}
	final += 1;
	return (final);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	long	total;
	char	*ptr;

	if (size == 0)
	{
		ptr = malloc(sizeof(char));
		*ptr = '\0';
		return (ptr);
	}
	total = get_total_size(size, strs, sep);
	ptr = malloc(sizeof(char) * total);
	if (ptr == NULL)
		return (NULL);
	*ptr = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(ptr, strs[i]);
		if (i + 1 < size)
			ft_strcat(ptr, sep);
		i++;
	}
	return (ptr);
}

/* int	main(void)
{
	char	*strs[3];
	char	*result;

	strs[0] = "42";
	strs[1] = "IS";
	strs[2] = "AWESOME";
	result = ft_strjoin(3, strs, ", ");
	if (result != NULL)
	{
		printf("%s\n", result);
		free(result);
	}
	return (0);
} */
