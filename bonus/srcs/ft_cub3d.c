/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:01:17 by lkonig            #+#    #+#             */
/*   Updated: 2021/01/20 15:33:09 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int				open_configfile(int argc, char **argv, int *save)
{
	int			fd;
	int			i;

	i = -1;
	fd = 0;
	*save = 0;
	if (argc < 2)
		error_init(0);
	else if (argc > 3)
		error_init(1);
	else if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
		error_init(2);
	else if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
		*save = 1;
	i = ft_strlen(argv[1]) - 4;
	if (i < 0 || ft_strcmp(argv[1] + i, ".cub") != 0)
		error_init(3);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		error_init(4);
	return (fd);
}

int				parse_free(char *line, t_param *param)
{
	int			k;

	k = 0;
	k = parse_configline(line, param);
	ft_free(line);
	if (k > 0)
		param->error = k;
	return (k);
}

void			parse_configfile(int fd, t_param *param)
{
	char		*line;
	int			res;

	res = 0;
	line = NULL;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		parse_free(line, param);
	}
	if (*line)
	{
		parse_free(line, param);
	}
	else
		ft_free(line);
	if (param->error != -1)
		error_parse(param->error, param);
	nb_sprite(param);
	get_finalmap(param);
	ft_sprite(param);
	parse_check(param);
	set_dirvect(param);
}

int				main(int argc, char *argv[])
{
	t_param		*param;
	int			fd;
	int			save;

	fd = open_configfile(argc, argv, &save);
	if (!(param = (t_param *)malloc(sizeof(t_param) * 1)))
		error_init(5);
	init_param(param);
	parse_configfile(fd, param);
	if (fd)
		close(fd);
	display(param, save);
	return (0);
}
