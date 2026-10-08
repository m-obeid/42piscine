/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobeid <mobeid@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 19:06:35 by mobeid            #+#    #+#             */
/*   Updated: 2026/10/08 12:01:12 by mobeid           ###   ########.fr       */
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

int		ft_atoi_base(char *str, char *base, int *out);
void	ft_putstr(char *str);
int		ft_check_base(char *base);

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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dlen;
	unsigned int	i;

	dlen = ft_strlen(dest);
	i = 0;
	while (i < nb && src[i] != '\0')
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dest);
}


void	ft_nbr_base_str(int nbr, char *base, char *str)
{
	int	baselen;

	baselen = ft_strlen(base);
	if (nbr < 0)
	{
		ft_strcat(str, "-");
		nbr = -nbr;
	}
	if (nbr > baselen - 1)
	{
		ft_nbr_base_str(nbr / baselen, base, str);
		ft_nbr_base_str(nbr % baselen, base, str);
	}
	else
		ft_strncat(str, &base[nbr], 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*ptr;
	int		dec;
	int		max;
	int		btlen;
	int		i;
 
	if (ft_atoi_base(nbr, base_from, &dec) == 0)
		return (NULL);
	btlen = ft_strlen(base_to);
	if (ft_check_base(base_to) == 0 || btlen < 2)
		return (NULL);
	max = 1;
	i = 1;
	while (max <= dec)
	{
		max *= btlen;
		i++;
	}
	ptr = malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (0);
	ft_nbr_base_str(dec, base_to, ptr);
	return (ptr);
}

int main(void)
{
	char	*res;

	res = ft_convert_base("120", "0123456789", "01");
	if (res == NULL)
	{
		ft_putstr("Invalid base or memory allocation failure!");
		return (1);
	}
	ft_putstr(res);
	free(res);
	return (0);
}
