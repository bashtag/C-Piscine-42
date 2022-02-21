/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgokce <bgokce@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 16:57:17 by bgokce            #+#    #+#             */
/*   Updated: 2022/02/20 17:23:24 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	if (*b != 0)
	{
		temp = (*a);
		*a = (*a) / (*b);
		*b = temp % (*b);
	}
}
