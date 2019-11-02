/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:59:45 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 13:58:08 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	print_usage(void)
{
	ft_printf("usage: ./fractol number_of_fractals\n\
	1 - julia\n\
	2 - mandelbrot\n\
	3 - burning ship\n\
	4 - buble way\n\
	5 - flower\n\
	6 - test\n\
	7 - tunnel\n\
	8 - plane\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	int			id;
	t_fractol	*fractol;

	if (argc != 2)
		print_usage();
	id = choose_fractol(argv[1]);
	fractol = setup_fractol(id);
	vis_thread(fractol);
	mlx_mouse_hook(fractol->win, &catch_mouse, fractol);
	mlx_hook(fractol->win, 6, 1L < 6, catch_x_y, fractol);
	mlx_key_hook(fractol->win, &catch_key, fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
