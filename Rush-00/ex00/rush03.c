/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sicalisk <sicalisk@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:09:23 by sicalisk          #+#    #+#             */
/*   Updated: 2022/02/21 20:43:53 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	horizontal_printer(char f_letter, char mid_letter, char s_letter, int x)
{
	int	horizontal_space;

	horizontal_space = x - 2;
	ft_putchar(f_letter);
	while (horizontal_space > 0)
	{
		ft_putchar(mid_letter);
		horizontal_space--;
	}
	if (x > 1)
		ft_putchar(s_letter);
	ft_putchar('\n');
}

void	top(int x)
{
	horizontal_printer('A', 'B', 'C', x);
}

void	mid(int x, int y)
{
	int	vertical_space;

	vertical_space = y - 2;
	if (y > 2)
	{
		while (vertical_space)
		{
			horizontal_printer('B', ' ', 'B', x);
			vertical_space--;
		}
	}
}

void	bot(int x, int y)
{
	if (y > 1)
	{
		horizontal_printer('A', 'B', 'C', x);
	}
}

void	rush(int x, int y)
{
	if (x > 0 && y > 0)
	{
		top(x);
		mid(x, y);
		bot(x, y);
	}
}
