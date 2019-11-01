/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:28:21 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/01 17:47:10 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_fractol		*setup_fractol(int id)
{
	t_fractol *fractol;

	fractol = ft_memalloc(sizeof(t_fractol));
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fractol");
	fractol->image = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->addr = (int *)mlx_get_data_addr(fractol->image, &fractol->bits_per_pixel,
											&fractol->size_line, &fractol->endian);
	fractol->id_fractol = id;
	fractol->zoom = 300;
	fractol->iteration = 50;
	fractol->mouse_x = -0.7;
	fractol->mouse_y = 0.27015;
	fractol->prev_mouse_x = 0;
	fractol->prev_mouse_y = 0;
	fractol->move_x = -2.1;
	fractol->move_y = -1.3;
	fractol->from_y = 0;
	fractol->to_y = HEIGHT;
	return (fractol);
}
