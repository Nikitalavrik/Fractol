/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:59:06 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/01 17:15:49 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

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
	int	x;
	int	y;
	int	color;
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
	// mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image, 0, 0);
}
