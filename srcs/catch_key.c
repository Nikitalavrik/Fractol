/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:32:45 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/28 20:27:35 by nlavrine         ###   ########.fr       */
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
	return (0);
}

int		catch_x_y(int x, int y, t_fractol *fractol)
{

	fractol->mouse_x = x;
	// fractol->mouse_y = y * 2 - HEIGHT;
	ft_printf("x = %i y = %i\n", x, y);
	ft_bzero(fractol->addr, WIDTH * HEIGHT * sizeof(int));
	vis_win(fractol);
	return (0);
}

int		catch_mouse(int button, int x, int y, t_fractol *fractol)
{

	if (button == 5)
		fractol->zoom *= 1.1;
	if (button == 4)
		fractol->zoom *= 0.9;
	ft_bzero(fractol->addr, WIDTH * HEIGHT * sizeof(int));
	vis_win(fractol);
	return (x + y);
}
