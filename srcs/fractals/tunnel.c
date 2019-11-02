/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunnel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:42:47 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 15:45:13 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			tunnel(t_complex z, t_complex c, int i)
{
	float tmp;

	tmp = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i > 1)
	{
		tmp = z.re / cos(z.re) + c.re;
		z.im = z.im / cos(z.im) - c.im;
		z.re = tmp;
		i--;
	}
	return (i);
}
