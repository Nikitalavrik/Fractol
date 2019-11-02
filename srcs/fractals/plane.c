/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:43:29 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 15:56:38 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			plane(t_complex z, t_complex c, int i)
{
	float tmp;

	tmp = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i > 1)
	{
		tmp = (z.re - 1) * (z.re + 0.5) *\
		(z.re * z.re - z.im * z.im - 1) + c.re;
		z.im = 2.0 * z.re * z.im + c.im;
		z.re = tmp;
		i--;
	}
	return (i);
}
