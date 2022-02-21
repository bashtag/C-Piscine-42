/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgokce <bgokce@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:36:33 by bgokce            #+#    #+#             */
/*   Updated: 2022/02/20 14:29:22 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_nums(char *num1, char *num2)
{
	write(1, num1, 2);
	write(1, " ", 1);
	write(1, num2, 2);
	if (num1[0] != '9' || num1[1] != '8')
		write(1, ", ", 2);
	num2[1]++;
	if (num2[1] > '9')
	{
		num2[0]++;
		num2[1] = '0';
	}
}

void	ft_print_comb2(void)
{
	char	num1[2];
	char	num2[2];

	num1[0] = '0';
	num1[1] = '0';
	while (num1[0] <= '9')
	{
		num2[0] = num1[0];
		num2[1] = num1[1] + 1;
		if (num2[1] > '9')
		{
			num2[0]++;
			num2[1] = '0';
		}
		while (num2[0] <= '9')
			ft_print_nums(num1, num2);
		num1[1]++;
		if (num1[1] > '9')
		{
			num1[0]++;
			num1[1] = '0';
		}
	}
}
