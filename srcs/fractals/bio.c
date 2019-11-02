/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bio.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:43:37 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 15:56:03 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			bio(t_complex z, t_complex c, int i)
{
	float	tmp;

	while ((z.re * z.re + z.im * z.im) < 4 && i > 1)
	{
		tmp = 2 * z.re * z.re - z.im * z.im + 1 / z.re + c.re;
		z.im = 2 * z.re * z.im + 1 / z.im + c.re;
		z.re = tmp;
		i--;
	}
	return (i + 20);
}
