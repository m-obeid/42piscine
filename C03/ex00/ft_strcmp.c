/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 10:27:59 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/01 13:06:50 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
/* int main(void)
{
	char	*str1;
	char	*str2;

	str1 = "42 Wolfsburg";
	str2 = "42 Berlin";
	return (ft_strcmp(str1, str2)); // should return 21
} */
