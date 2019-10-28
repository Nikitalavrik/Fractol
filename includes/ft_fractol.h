/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:59:36 by nlavrine          #+#    #+#             */
/*   Updated: 2019/10/28 20:20:24 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# include "../libft/libft.h"
# include <fcntl.h>
# include "../libft/ft_printf/include/ft_printf.h"
# include "../minilibx_macos/mlx.h"

# define HEIGHT 720
# define WIDTH	1280
# define MAX_FRACTOLS 1

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*image;
	int			id_fractol;
	int			*addr;
	int			deep;
	int			iteration;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			height;
	int			width;
	int			music_on;
	float		zoom;
	float			mouse_x;
	float			mouse_y;
}				t_fractol;

typedef int		t_func(t_fractol *fractol, int x, int y);

t_fractol		*setup_fractol(int id);

int				catch_x_y(int x, int y, t_fractol *fractol);
int				catch_mouse(int button, int x, int y, t_fractol *fractol);
int				catch_key(int key, t_fractol *fractol);
int				choose_fractol(char *argv);
t_func		 	*get_func(int id);

void			vis_win(t_fractol *fractol);

void			print_error(char *message);

#endif