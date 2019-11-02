/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:59:36 by nlavrine          #+#    #+#             */
/*   Updated: 2019/11/02 16:36:00 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <pthread.h>
# include "../libft/ft_printf/include/ft_printf.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

# define HEIGHT 720
# define WIDTH	1280
# define MAX_FRACTOLS 8
# define MONITOR_HEIGHT 2880
# define MONITOR_WIDTH 5120
# define THREADS_NUM 8
# define START_ZOOM 300
# define START_X_MOVE -2.1
# define START_Y_MOVE -1.3

typedef	struct	s_complex
{
	float		re;
	float		im;
}				t_complex;

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*image;
	int			id_fractol;
	int			*addr;
	int			iteration;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			from_x;
	int			to_x;
	int			from_y;
	int			to_y;
	float		zoom;
	float		mouse_x;
	float		mouse_y;
	float		move_x;
	float		move_y;
	int			stop;
	int			show_menu;
}				t_fractol;

typedef int		t_func(t_complex z, t_complex c, int i);

t_fractol		*setup_fractol(int id);

int				catch_x_y(int x, int y, t_fractol *fractol);
int				catch_mouse(int button, int x, int y, t_fractol *fractol);
int				catch_key(int key, t_fractol *fractol);
int				choose_fractol(char *argv);
t_func			*get_func(int id);

int				brute_fractol(t_fractol *fractol, int x, int y, t_func func);

void			vis_thread(t_fractol *fractol);
void			vis_win(t_fractol *fractol);
void			string_toolbar(t_fractol *fractol);

int				bio(t_complex z, t_complex c, int i);
int				buble_way(t_complex z, t_complex c, int i);
int				burning_ship(t_complex z, t_complex c, int i);
int				flower(t_complex z, t_complex c, int i);
int				mandelbrot_set(t_complex z, t_complex c, int i);
int				plane(t_complex z, t_complex c, int i);
int				tunnel(t_complex z, t_complex c, int i);

void			print_error(char *message);

#endif
