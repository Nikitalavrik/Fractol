/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:45:58 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 16:19:04 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			choose_fractol(char *argv)
{
	int	id;

	id = ft_atoi(argv);
	if (ft_strlen(argv) > 1 || id <= 0 || id > MAX_FRACTOLS)
		print_error("MAX_FRACTOLS 8\n");
	return (id);
}

int			brute_fractol(t_fractol *fractol, int x, int y, t_func func)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z.re = x / fractol->zoom + fractol->move_x;
	z.im = y / fractol->zoom + fractol->move_y;
	c.re = fractol->id_fractol == 1 ? fractol->mouse_x : z.re;
	c.im = fractol->id_fractol == 1 ? fractol->mouse_y : z.im;
	i = fractol->iteration;
	return (func(z, c, i));
}

t_func		*get_func(int id)
{
	t_func *fractol_func[8];

	fractol_func[0] = &mandelbrot_set;
	fractol_func[1] = &mandelbrot_set;
	fractol_func[2] = &burning_ship;
	fractol_func[3] = &buble_way;
	fractol_func[4] = &flower;
	fractol_func[5] = &bio;
	fractol_func[6] = &tunnel;
	fractol_func[7] = &plane;
	return (fractol_func[id - 1]);
}
