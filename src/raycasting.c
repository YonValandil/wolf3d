#include "wolf.h"

void 		ray_scan(t_env *env)
{
	x = -1;
	while (++x < WIDTH_IMG)
	{
		env->player.cam.x = 2 * x / double(WIDTH_IMG) - 1;//
		env->ray.pos.x = env->player.pos.x;
		env->ray.pos.y = env->player.pos.y;
		env->ray.dir.x = env->player.dir.x + planeX * env->player.cam.x;//
		env->ray.dir.y = env->player.dir.y + planeY * env->player.cam.x;//

		mapX = int(env->ray.pos.x);
		mapY = int(env->ray.pos.y;

		//calcul avec pythagore du delta ()
	   	env->ray.delta.x = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		env->ray.delta.y = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;//??

		// on part du principe que le rayon ne touche pas de murs (ni en x ni en y)
		env->ray.hit = 0;

		//a venir calcul de side
	}
}

void 		horizon_line(t_env *env)
{
}

void 		draw_wall(t_env *env)
{
}

void 		wolf_loop(t_env *env)
{
	while (1)
	{
		ray_scan(env); //raycast?
		horizon_line(env);
		draw_wall(env);
	}
}
