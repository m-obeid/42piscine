/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 11:01:41 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/05 10:52:18 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	len;

	len = 0;
	while (*str != '\0' && *to_find != '\0')
	{
		if (to_find[len] == *str)
			len++;
		else
		{
			str -= len;
			len = 0;
		}
		if (ft_strlen(to_find) == len)
		{
			str -= ft_strlen(to_find) - 1;
			return (str);
		}
		str++;
	}
	return (0);
}

/* int main(void)
{
	// This test main function prints starting from where res points, so it 
	// should start with "needle"
	char	*haystack;
	char	*needle;
	char	*res;

	haystack = "Try to find the \"needle\" in this haystack of a string.";
	needle = "needle";
	res = ft_strstr(haystack, needle);
	if (res != 0)
		printf("... %s", res);
	else
		printf("none");
	return (0);
} */
