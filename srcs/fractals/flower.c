/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flower.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:42:57 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 15:45:00 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

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
