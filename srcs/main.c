/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:59:45 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/31 14:27:15 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int		main(int argc, char **argv)
{
	int			id;
	t_fractol 	*fractol;

	if (argc != 2)
		print_error("Where is file ?\n");
	id = choose_fractol(argv[1]);
	fractol = setup_fractol(id);
	vis_thread(fractol);
	mlx_mouse_hook(fractol->win, &catch_mouse, fractol);
	mlx_hook(fractol->win, 6, 1L < 6, catch_x_y, fractol);
	mlx_key_hook(fractol->win, &catch_key, fractol);
	mlx_loop(fractol->mlx);	
	return (0);
}
