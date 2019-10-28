/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:03:32 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/28 16:04:44 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void		print_error(char *message)
{
	int i;

	i = 0;
	while (message[i])
	{
		write(2, &(message[i]), 1);
		i++;
	}
	exit(0);
}