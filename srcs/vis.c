/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:59:06 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/28 19:38:37 by nlavrine         ###   ########.fr       */
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

	y = 0;
	color = 0;
	func = get_func(fractol->id_fractol);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = func(fractol, x, y);
			// ft_printf("color = %i\n", color);
			color = convert(color);
			// ft_printf("convert = %i\n", color);
			put_pixel(fractol, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image, 0, 0);
}
