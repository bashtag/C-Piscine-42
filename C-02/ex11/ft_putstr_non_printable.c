/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgokce <bgokce@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:38:25 by bgokce            #+#    #+#             */
/*   Updated: 2022/02/22 16:11:21 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (
		str[++len]);
	return (len);
}

void	ft_put_hex(int nbr, int counter)
{
	if (nbr > 15)
	{
		ft_put_hex(nbr / 16, 1);
		counter++;
	}
	if (counter == 0)
		write(1, "0", 1);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	len;
	int	i;
	int	is_single;

	is_single = 0;
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] >= 32 && str[i] != 127)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			ft_put_hex(str[i], is_single);
		}
		i++;
	}
}
