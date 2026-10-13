/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:14:00 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/12 18:06:00 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ic(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = i - 1;
		if (ic(str[i], charset) == 0 && (i == 0 || ic(str[j], charset) == 1))
			cnt++;
		i++;
	}
	return (cnt);
}

char	*ft_wddup(char *src, char *charset)
{
	int		i;
	int		slen;
	char	*ptr;

	i = 0;
	slen = 0;
	while (ic(src[slen], charset) != 1)
		slen++;
	ptr = malloc((slen + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < slen)
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL || charset == NULL)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (strs == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && ic(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
		{
			strs[j] = ft_wddup(&str[i], charset);
			j++;
			while (str[i] != '\0' && ic(str[i], charset) == 0)
				i++;
		}
	}
	strs[j] = NULL;
	return (strs);
}

/* int	main(void)
{
	char	**test;

	test = ft_split(",,Hello world,,test", ",");
	printf("%s ------- %s", test[0], test[1]);
	return (0);
} */
