/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:32:45 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/01 20:03:37 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	exit_fractol(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	// turn_on_music(fractol, key);
	exit(0);
}

int		catch_key(int key, t_fractol *fractol)
{
	if (key == 53)
		exit_fractol(fractol);
	if (key == 78)
		fractol->iteration--;
	if (key == 69)
		fractol->iteration++;
	if (key == 123)
		fractol->move_x += 1;
	if (key == 124)
		fractol->move_x -= 1;
	if (key == 126)
		fractol->zoom *= 1.1;
	if (key == 125)
		fractol->zoom *= 0.9;
	if (key == 49)
		fractol->stop = fractol->stop ? 0 : 1;
	// ft_printf("move_x %f\n", fractol->move_x);
	// ft_printf("key = %i\n", key);
	// ft_printf("zoom = %f\n", fractol->zoom);
	ft_printf("c.re = %f c.im = %f\n", fractol->mouse_x, fractol->mouse_y);
	ft_bzero(fractol->addr, WIDTH * HEIGHT * sizeof(int));
	vis_thread(fractol);
	return (0);
}

int		catch_x_y(int x, int y, t_fractol *fractol)
{
	if (!fractol->stop)
	{
		fractol->mouse_x = ((float)x / MONITOR_WIDTH) - 0.8;
		fractol->mouse_y = ((float)y / MONITOR_HEIGHT) + 0.2;
		fractol->prev_mouse_x = x;
		fractol->prev_mouse_y = y;
		ft_bzero(fractol->addr, WIDTH * HEIGHT * sizeof(int));
		vis_thread(fractol);
	}
	return (0);
}

int		catch_mouse(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
	{
		fractol->move_x = (x / fractol->zoom + fractol->move_x) - (x / (fractol->zoom * 1.1));
		fractol->move_y = (y / fractol->zoom + fractol->move_y) - (y / (fractol->zoom * 1.1));
		fractol->zoom *= 1.1;
		fractol->iteration++;
	}

	if (button == 5)
	{
		fractol->move_x = (x / fractol->zoom + fractol->move_x) - (x / (fractol->zoom * 0.9));
		fractol->move_y = (y / fractol->zoom + fractol->move_y) - (y / (fractol->zoom * 0.9));
		fractol->zoom *= 0.9;
		fractol->iteration--;
	}
	// ft_printf("move_x %f move_y %f zoom = %f\n", fractol->move_x, fractol->move_y, fractol->zoom);
	// ft_printf("button = %i\n", button);
	ft_bzero(fractol->addr, WIDTH * HEIGHT * sizeof(int));
	vis_thread(fractol);
	return (0);
}
