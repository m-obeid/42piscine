/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 12:35:15 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/01 16:17:16 by mobeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i != 0 && !ft_isalnum(str[i - 1]) && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (i != 0 && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

/* int main(int argc, char const *argv[])
{
	char	test[] = "hi, how are you? 42words forty-two; fifty+and+one";

	ft_strcapitalize(test);
	printf("%s", test);
	return 0;
} */
