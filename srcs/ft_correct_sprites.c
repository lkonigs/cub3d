#include "../cub3d.h"

#include <stdio.h> //

int		correct_mincol(double angle, t_param *p, int k)
{
	t_point	a;
	double	tan;

	tan = set_tan(angle);
	a = init_ptv(angle, a, p, tan);
	while (a.pos.y > 0 && a.pos.y < p->mapsize.y * 64 &&
		p->map[(int)a.pos.y][(int)a.pos.x] != '1')
	{
		if ((p->map[(int)a.pos.y][(int)a.pos.x] == '2')
			&& (check_inter_sp(a, p, k)))
		{
			p->sprites[k].col--;
			return (1);
		}
		a = update_pointv(a, angle, tan);
	}
	angle = p->player.angle + FOV / 2;
	a = init_pth(angle, a, p, tan);
	while (a.pos.x > 0 && a.pos.x < ft_strlen(p->map[(int)a.pos.y]) &&
		p->map[(int)a.pos.y][(int)a.pos.x] != '1')
	{
		if ((p->map[(int)a.pos.y][(int)a.pos.x] == '2')
			&& (check_inter_sp(a, p, k)))
		{
			p->sprites[k].col--;
			return (1);
		}
		a = update_pointh(a, angle, tan);
	}
	return (0);
}

int		correct_maxcol(double angle, t_param *p, int k)
{
	t_point	a;
	double	tan;

	tan = set_tan(angle);
	a = init_ptv(angle, a, p, tan);
	while (a.pos.y > 0 && a.pos.y < p->mapsize.y * 64 &&
		p->map[(int)a.pos.y][(int)a.pos.x] != '1')
	{
		if ((p->map[(int)a.pos.y][(int)a.pos.x] == '2')
			&& (check_inter_sp(a, p, k)))
		{
			p->sprites[k].maxcol++;
			return (1);
		}
		a = update_pointv(a, angle, tan);
	}
	angle = p->player.angle - FOV / 2;
	a = init_pth(angle, a, p, tan);
	while (a.pos.x > 0 && a.pos.x < ft_strlen(p->map[(int)a.pos.y]) &&
		p->map[(int)a.pos.y][(int)a.pos.x] != '1')
	{
		if ((p->map[(int)a.pos.y][(int)a.pos.x] == '2')
			&& (check_inter_sp(a, p, k)))
		{
			p->sprites[k].maxcol++;
			return (1);
		}
		a = update_pointh(a, angle, tan);
	}
	return (0);
}

void        correct_sprite(t_param *p)
{
	unsigned int     k;
	double  angle;
//	int     col;

	k = -1;
	while (++k < p->nb_sprite)
	{
		if ((p->sprites[k].visible == 1)
			&& (p->sprites[k].col == 0))
		{
	//		printf("sprite #%u, old p->sprites[k].col = %i\n", k, p->sprites[k].col);
			angle = p->player.angle + FOV / 2;
	//		col = 0;
			while (correct_mincol(angle, p, k))
			{
				angle += p->plane.angles;
		//		col--;
			}
	//		printf("sprite #%u, new p->sprites[k].col = %i\n", k, p->sprites[k].col);
		}
		if ((p->sprites[k].visible == 1)
			&& (p->sprites[k].maxcol == p->res.x - 1))
		{
	//		printf("sprite #%u, old p->sprites[k].maxcol = %i\n", k, p->sprites[k].maxcol);
			angle = p->player.angle - FOV / 2;
	//		col = p->res.x - 1;
			while (correct_maxcol(angle, p, k))
			{
				angle -= p->plane.angles;
			}
	//		printf("sprite #%u, new p->sprites[k].maxcol = %i\n", k, p->sprites[k].maxcol);
		}
	}
}