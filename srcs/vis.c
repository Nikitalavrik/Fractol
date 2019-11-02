/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:59:06 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 14:53:30 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		string_toolbar(t_fractol *fractol)
{
	int c;
	int	width;

	c = 0x2795a3;
	width = WIDTH - 250;
	mlx_string_put(fractol->mlx, fractol->win, width + 60, 10, c, "MENU");
	mlx_string_put(fractol->mlx, fractol->win, width, 30, c, "H  - show menu");
	mlx_string_put(fractol->mlx, fractol->win, width, 50, c, "^  - move up");
	mlx_string_put(fractol->mlx, fractol->win, width, 70, c, "v  - move down");
	mlx_string_put(fractol->mlx, fractol->win, width, 90, c, "<- - move left");
	mlx_string_put(fractol->mlx, fractol->win, width, 110, c, "-> - \
																move right");
	mlx_string_put(fractol->mlx, fractol->win, width, 130, c, "+  - \
														increase iteration");
	mlx_string_put(fractol->mlx, fractol->win, width, 150, c, "-  - \
														decrease iteration");
	mlx_string_put(fractol->mlx, fractol->win, width, 170, c, "scroll up - \
																zoom in");
	mlx_string_put(fractol->mlx, fractol->win, width, 190, c, "scroll down - \
																zoom out");
	mlx_string_put(fractol->mlx, fractol->win, width, 210, c, "1-8 - \
														change fractals");
	mlx_string_put(fractol->mlx, fractol->win, width, 230, c, "ESC - exit");
}

void		put_pixel(t_fractol *fractol, int x, int y, int color)
{
	int pos;

	pos = x + y * WIDTH;
	if (pos < WIDTH * HEIGHT)
		fractol->addr[pos] = color;
}

int			convert(int color)
{
	return ((color << 21) + (color << 10) + (color * 8));
}

void		vis_win(t_fractol *fractol)
{
	int		x;
	int		y;
	int		color;
	t_func	*func;

	y = fractol->from_y;
	color = 0;
	func = get_func(fractol->id_fractol);
	while (y < fractol->to_y)
	{
		x = fractol->from_x;
		while (x < fractol->to_x)
		{
			color = brute_fractol(fractol, x, y, func);
			color = convert(color);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
}
