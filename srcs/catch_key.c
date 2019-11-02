/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:32:45 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 16:33:57 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		exit_fractol(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	exit(0);
}

void		grep_key_fractol(t_fractol *fractol, int key)
{
	int		id_fractol;

	id_fractol = key - 17;
	if (id_fractol == 9)
		id_fractol = 7;
	if (id_fractol == 11)
		id_fractol = 8;
	fractol->id_fractol = id_fractol;
	fractol->zoom = START_ZOOM;
	fractol->move_x = START_X_MOVE;
	fractol->move_y = START_Y_MOVE;
	fractol->iteration = 50;
}

int			catch_key(int key, t_fractol *fractol)
{
	if (key == 53)
		exit_fractol(fractol);
	if (key == 78)
		fractol->iteration--;
	if (key == 69)
		fractol->iteration++;
	if (key == 123)
		fractol->move_x += WIDTH / (10 * fractol->zoom);
	if (key == 124)
		fractol->move_x -= WIDTH / (10 * fractol->zoom);
	if (key == 126)
		fractol->move_y += HEIGHT / (10 * fractol->zoom);
	if (key == 125)
		fractol->move_y -= HEIGHT / (10 * fractol->zoom);
	if (key == 49)
		fractol->stop = fractol->stop ? 0 : 1;
	if (key == 4)
		fractol->show_menu = fractol->show_menu ? 0 : 1;
	if (key >= 18 && key <= 28 && key != 27 && key != 25 && key != 24)
		grep_key_fractol(fractol, key);
	ft_bzero(fractol->addr, WIDTH * HEIGHT * sizeof(int));
	vis_thread(fractol);
	return (0);
}

int			catch_x_y(int x, int y, t_fractol *fractol)
{
	if (!fractol->stop)
	{
		fractol->mouse_x = ((float)x / MONITOR_WIDTH) - 0.8;
		fractol->mouse_y = ((float)y / MONITOR_HEIGHT) + 0.2;
		ft_bzero(fractol->addr, WIDTH * HEIGHT * sizeof(int));
		vis_thread(fractol);
	}
	return (0);
}

int			catch_mouse(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
	{
		fractol->move_x = (x / fractol->zoom + fractol->move_x)\
		- (x / (fractol->zoom * 1.1));
		fractol->move_y = (y / fractol->zoom + fractol->move_y)\
		- (y / (fractol->zoom * 1.1));
		fractol->zoom *= 1.1;
		fractol->iteration++;
	}
	if (button == 5)
	{
		fractol->move_x = (x / fractol->zoom + fractol->move_x)\
		- (x / (fractol->zoom * 0.9));
		fractol->move_y = (y / fractol->zoom + fractol->move_y)\
		- (y / (fractol->zoom * 0.9));
		fractol->zoom *= 0.9;
		fractol->iteration--;
	}
	ft_bzero(fractol->addr, WIDTH * HEIGHT * sizeof(int));
	vis_thread(fractol);
	return (0);
}
