/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buble_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:43:16 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 15:56:29 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int			buble_way(t_complex z, t_complex c, int i)
{
	float tmp;

	tmp = 0;
	while ((z.re * z.re + z.im * z.im) < 4 && i > 1)
	{
		tmp = exp(z.re) * cosf(z.im) + c.re;
		z.im = exp(z.re) * sinf(z.im) + c.im;
		z.re = tmp;
		i--;
	}
	return (i);
}
