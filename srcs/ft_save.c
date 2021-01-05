/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:17:17 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 15:18:36 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned char				*write_pix(int fd, int i, t_param *param)
{
	unsigned char			*pix;

	pix = (unsigned char*)&param->imgstr[i];
	write(fd, pix, 3);
	return (pix);
}

void						ft_save(t_param *param, char *pathname)
{
	int						fd;
	int						y;
	int						i;
	int						k;
	unsigned char			*pix;

	create_image(param);
	fd = open(pathname, O_TRUNC | O_WRONLY | O_CREAT, S_IWUSR
		| S_IRUSR | S_IWGRP | S_IRGRP | S_IWOTH | S_IROTH);
	y = param->res.y;
	set_bmpheader(param, fd);
	while (--y >= 0)
	{
		i = y * param->res.x * 4;
		k = 0;
		while (k++ < param->res.x)
		{
			pix = write_pix(fd, i, param);
			i += 4;
		}
		write(fd, pix, param->res.x % 4);
	}
	close(fd);
	free(param->imgptr);
	ft_exit(param);
}

void						set_bmpheader(t_param *param, int fd)
{
	static unsigned char	header[54] = {66, 77, 0, 0, 0, 0, 0, 0, 0,
		0, 54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24};
	unsigned int			*ptr;

	ptr = (unsigned int *)&header[2];
	*ptr = 54 + param->res.x * param->res.y * 3
		+ (param->res.x % 4) * param->res.x;
	ptr = (unsigned int *)&header[18];
	*ptr = param->res.x;
	ptr = (unsigned int *)&header[22];
	*ptr = param->res.y;
	ptr = (unsigned int *)&header[34];
	*ptr = param->res.x * param->res.y * 3
		+ (param->res.x % 4) * param->res.x;
	ptr = (unsigned int *)&header[38];
	*ptr = 3780;
	ptr = (unsigned int *)&header[42];
	*ptr = 3780;
	write(fd, header, 54);
}
