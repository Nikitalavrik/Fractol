/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:45:58 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/01 20:12:28 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int		choose_fractol(char *argv)
{
	int	id;

	id = ft_atoi(argv);
	if (ft_strlen(argv) > 1 || id <= 0 || id > MAX_FRACTOLS)
		print_error("MAX_FRACTOLS 1\n");
	return (id);
}

int			mandelbrot_set(t_complex z, t_complex c, int i)
{
	float tmp;

	tmp = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i > 1)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		i--;
	}
	return (i);
}

int			test(t_complex z, t_complex c, int i)
{
	float tmp;

	tmp = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i > 1)
	{
		tmp = z.re * z.re - z.im * z.im  + z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		i--;
	}
	return (i);
}

int			flower(t_complex z, t_complex c, int i)
{
	float tmp;

	tmp = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i > 1)
	{
		tmp = fabs(z.re * z.re - z.im * z.im) + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		i--;
	}
	return (i);
}

int			burning_ship(t_complex z, t_complex c, int i)
{
	float tmp;

	tmp = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i > 1)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2.0 * fabs(z.re * z.im) + c.im;
		z.re = tmp;
		i--;
	}
	return (i);
}

int			buble_way(t_complex z, t_complex c, int i)
{
	float tmp;

	tmp = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i > 1)
	{
		tmp = exp(z.re) * cosf(z.im) + c.re;
		z.im = exp(z.re) * sinf(z.im) +  c.im;
		z.re = tmp;
		i--;
	}
	return (i);
}

int			brute_fractol(t_fractol *fractol, int x, int y, t_func func)
{
	t_complex	z;
	t_complex	c;
	int			i;

	z.re = x / fractol->zoom + fractol->move_x;
	z.im = y / fractol->zoom + fractol->move_y;
	c.re = fractol->id_fractol == 6 ? fractol->mouse_x : z.re;
	c.im = fractol->id_fractol == 6 ? fractol->mouse_y : z.im;;
	i = fractol->iteration;
	return (func(z, c, i));
}

t_func *get_func(int id)
{
	t_func *fractol_func[6] =
	{&mandelbrot_set, &mandelbrot_set, &burning_ship, &buble_way, &flower, &test};
	return (fractol_func[id - 1]);
}
