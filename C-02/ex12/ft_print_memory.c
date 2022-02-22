/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgokce <bgokce@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:11:34 by bgokce            #+#    #+#             */
/*   Updated: 2022/02/22 14:19:07 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_put_zero = 0;

void	ft_put_hex(unsigned long long nbr)
{
	if (nbr > 15)
	{
		g_put_zero++;
		ft_put_hex(nbr / 16);
	}
	while (15 - g_put_zero > 0)
	{
		write(1, "0", 1);
		g_put_zero++;
	}
	write(1, &"0123456789abcdef"[nbr % 16], 1);
}

void	ft_put_two_hex(char ch)
{
	if (ch > 15)
	{
		g_put_zero++;
		ft_put_two_hex(ch / 16);
	}
	if (g_put_zero == 0)
		write(1, "0", 1);
	write(1, &"0123456789abcdef"[ch % 16], 1);
}

void	ft_print_with_non_printable(char *str, int index)
{
	int	i;
	int	counter;

	i = index - 16;
	counter = 0;
	while (str[i] && counter < 16)
	{
		if (str[i] >= 32 && str[i] != 127)
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
		counter++;
	}
}

void	ft_print_hex_and_string(char *str)
{
	unsigned long long	dec_address;
	unsigned long long	i;

	i = 0;
	while (str[i])
	{
		dec_address = (unsigned long long)&str[i];
		ft_put_hex(dec_address);
		g_put_zero = 0;
		write(1, ":", 1);
		while (str[i])
		{
			if (i % 2 == 0)
				write(1, " ", 1);
			ft_put_two_hex(str[i]);
			g_put_zero = 0;
			i++;
			if (i % 16 == 0)
				break ;
		}
		write(1, " ", 1);
		ft_print_with_non_printable(str, i);
		write(1, "\n", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*addptr;

	if (size == 0)
		return (addr);
	addptr = (char *)addr;
	ft_print_hex_and_string(addptr);
	return (addr);
}
