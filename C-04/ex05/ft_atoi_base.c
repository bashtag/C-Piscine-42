/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgokce <bgokce@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:25:58 by bgokce            #+#    #+#             */
/*   Updated: 2022/02/24 13:04:21 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (
		str[++len]);
	return (len);
}

int	ft_number(char base_num, char *base)
{
	int	i;

	i = -1;
	while (
		base[++i] && base[i] != base_num);
	return (i);
}

int	ft_is_valid(char base_num, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != base_num)
		i++;
	if (base[i] == '\0')
		return (0);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	base_len;
	int	sign;

	base_len = ft_strlen(base);
	result = 0;
	sign = 1;
	i = -1;
	while (
		str[++i] == ' ');
	while (str[i] == '+' || str[i] == '-'
		|| (str[i] == '0' && str[++i] == 'x'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_is_valid(str[i], base))
	{
		result = result * base_len + ft_number(str[i], base);
		i++;
	}
	return (result * sign);
}
