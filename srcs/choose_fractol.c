/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:45:58 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/28 20:20:38 by nlavrine         ###   ########.fr       */
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

int			julia(t_fractol *fractol, int x, int y)
{
	float	zx;
	float	zy;
	float	i;
	float	tmp;
	float	cx;
	float	cy;

	cx = fractol->mouse_x;
	cy = fractol->mouse_y;
	zx = 1.5 * (x - WIDTH / 2) / (0.5 * fractol->zoom * WIDTH);
	zy = 1.0 * (y - HEIGHT / 2) / (0.5 * fractol->zoom * HEIGHT);
	i = fractol->iteration;
	while ((zx * zx + zy * zy) < 4 && i > 1)
	{
		tmp = zx * zx - zy * zy + cx;
		zy = 2.0 * zx * zy + cy;
		zx = tmp;
		i--;
	}
	return (i);
}

t_func *get_func(int id)
{
	t_func *fractol_func[1] =
	{&julia};
	return (fractol_func[id - 1]);
}
