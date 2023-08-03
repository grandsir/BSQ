/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 10:23:14 by databey           #+#    #+#             */
/*   Updated: 2023/07/29 11:23:00 by databey          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	open_file(t_map_info *info, char *file)
{
	int	fd;

	fd = open(file, 0);
	if (fd == -1)
		info->err = 1;
	info->fd = fd;
}

void	parse_params(t_map_info *info)
{
	int		j;
	int		i;
	char	c;
	char	height_info[500];

	i = 0;
	j = 0;
	while (read(info->fd, &c, 1))
	{
		if (i == 0)
			height_info[j++] = c;
		if (i == 1 && c != '\n')
			info->width += 1;
		if (i == 2)
			break ;
		if (c == '\n')
			i++;
	}
	info->height = ft_map_atoi(height_info, info);
	if (!info->height)
		info->err = 1;
}

void	save_contents(t_map_info *info)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (read(info->fd, &c, 1) > 0)
	{
		if (c == '\n')
		{
			if (i > 0 && j != info->width)
				info->err = 1;
			j = 0;
			i++;
			continue ;
		}
		if (i > 0)
		{
			if (c != info->obstacle && c != info->empty)
				info->err = 1;
			info->map[i - 1][j] = c;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_map_info	info;
	int			j;

	j = 1;
	if (argc == 1)
	{
		read_from_standard_input(&info);
	}
	else
	{
		while (j < argc)
		{
			read_from_arguments(argv[j], &info);
			if (++j < argc)
				ft_putchar('\n');
		}
	}
}
