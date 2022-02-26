/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgokce <bgokce@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:34:17 by bgokce            #+#    #+#             */
/*   Updated: 2022/02/24 11:36:47 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (
		str[++len]);
	return (len);
}

void	ft_is_base_true(char *base, int *is_valid)
{
	int	i;
	int	j;

	if (*base == '\0' || *(base + 1) == '\0')
		*is_valid = 0;
	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' && base[i] == '-')
			*is_valid = 0;
		while (base[j] != '\0')
		{
			if (i != j && base[j] == base[i])
				*is_valid = 0;
			j++;
		}
		i++;
	}
}

void	ft_nbr_base(int nb, char *base)
{
	int			len;
	long long	long_nb;

	long_nb = nb;
	len = ft_strlen(base);
	if (long_nb < 0)
	{
		write(1, "-", 1);
		long_nb *= -1;
	}
	if (long_nb > len - 1)
		ft_nbr_base(long_nb / len, base);
	write(1, &base[long_nb % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	is_valid;

	is_valid = 1;
	ft_is_base_true(base, &is_valid);
	if (!is_valid)
		return ;
	ft_nbr_base(nbr, base);
}
