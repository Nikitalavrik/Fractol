/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:43:06 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 15:44:53 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

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
