/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:58:52 by jjourne           #+#    #+#             */
/*   Updated: 2017/12/10 19:41:58 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_string(t_env *env)
{
	mlx_string_put(env->mlx, env->win.ptr, 20, 20, GREEN,
		"press ESC: QUIT");
	mlx_string_put(env->mlx, env->win.ptr, 20, 40, GREEN,
		"press SPACE: RESET");
}

void	set_img(t_env *env)
{
	env->img.ptr = mlx_new_image(env->mlx, env->img.l, env->img.h);
	env->img.data = mlx_get_data_addr(env->img.ptr, &env->img.bpp,
		&env->img.size_line, &env->img.endian);
	mlx_clear_window(env->mlx, env->win.ptr);
	ray_loop(env);
	mlx_put_image_to_window(env->mlx, env->win.ptr, env->img.ptr, 0, 0);
	set_string(env);
	mlx_destroy_image(env->mlx, env->img.ptr);
}

void 	set_player(t_env *env)
{
	env->player.size = 32;
	env->player.pos.x = 2;
	env->player.pos.y = 2;
	env->player.dir.x = -1;
	env->player.dir.y = 0;
	env->player.rot = 0;//M_PI / (double)25;
	env->speed = 0.1;
}

void 	set_color_wall(t_env *env)
{

}

void	set_env(t_env *env)
{
	env->win.l = WIDTH;
	env->win.h = HEIGHT;
	env->win.title = ft_strdup("mlx 42 wolf3d");
	env->img.l = WIDTH_IMG;
	env->img.h = HEIGHT_IMG;
	env->map = NULL;
	env->nbr_line = 0;
	env->nbr_col = 0;
	set_player(env);
	set_color_wall(env);
}
