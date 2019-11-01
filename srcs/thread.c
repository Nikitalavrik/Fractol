/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:49:08 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/31 16:24:27 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	vis_thread(t_fractol *fractol)
{
	int		i;
	pthread_t		thread[THREADS_NUM];
	t_fractol	fractols[THREADS_NUM];

	i = 0;
	while (i < THREADS_NUM)
	{
		fractols[i] = *fractol;
		fractols[i].from_x = i * (WIDTH / THREADS_NUM);
		fractols[i].to_x = (i + 1) * (WIDTH / THREADS_NUM);
		pthread_create(&thread[i], NULL, (void *)&vis_win, &fractols[i]);
		i++;
	}
	i = 0;
	while (i < THREADS_NUM)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image, 0, 0);
}
