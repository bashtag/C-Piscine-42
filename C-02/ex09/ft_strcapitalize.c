/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgokce <bgokce@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:51:37 by bgokce            #+#    #+#             */
/*   Updated: 2022/02/22 13:10:00 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ch_is_alpha(char ch)
{
	if (ch < 'A' || (ch > 'Z' && ch < 'a') || ch > 'z')
		return (0);
	return (1);
}

int	ft_ch_is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_strlowcase(str);
	if (str[0] <= 'z' && str[0] >= 'a')
		str[0] -= 32;
	i = 0;
	while (str[i])
	{
		if (!ft_ch_is_alpha(str[i]) && ft_ch_is_alpha(str[i + 1])
			&& !ft_ch_is_digit(str[i]))
			str[i + 1] -= 32;
		i++;
	}
	return (str);
}
