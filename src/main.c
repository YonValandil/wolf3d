/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 06:08:31 by jjourne           #+#    #+#             */
/*   Updated: 2017/12/10 19:41:16 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

void	del_map(void *map, size_t size)
{
	(void)size;
	ft_memdel((void*)&map);
}

t_coords	set_pixel(int x, int y, int color)
{
	t_coords p;

	p.x = x;
	p.y = y;
	p.color = color;
	return (p);
}

void	put_pixel_img(t_env *env, t_coords p)
{
	int r;
	int g;
	int b;

	r = (p.color & 0xFF0000) >> 16;
	g = (p.color & 0xFF00) >> 8;
	b = (p.color & 0xFF);
	if (p.y >= 0 && p.x >= 0 && p.y < HEIGHT_IMG && p.x < WIDTH_IMG)
	{
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x) + 2] = r;
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x) + 1] = g;
		env->img.data[(p.y * env->img.size_line) +
			((env->img.bpp / 8) * p.x)] = b;
	}
}

int		main(int argc, char *argv[])
{
	t_env env;

	if (argc != 2)
		exit_error("usage: ./wolfd3d File");
	set_env(&env);
	parse(&env, argv[1]);
	env.mlx = mlx_init();
	env.win.ptr = mlx_new_window(env.mlx, env.win.l, env.win.h, env.win.title);
	set_img(&env);
	// mlx_hook(env.win.ptr, 2, 3, controller, &env);
	mlx_loop(env.mlx);
	return (0);
}
