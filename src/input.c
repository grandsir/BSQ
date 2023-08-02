/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:11:04 by databey           #+#    #+#             */
/*   Updated: 2023/08/02 16:11:06 by databey          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	check_error(t_map_info *info)
{
	if (info->err)
	{
		map_invalid_error(info);
		return (1);
	}
	return (0);
}

void	read_from_arguments(char *file, t_map_info *info)
{
	int	i;

	open_file(info, file);
	if (check_error(info))
		return ;
	parse_params(info);
	open_file(info, file);
	i = 0;
	info->map = (char **)malloc(sizeof(char *) * info->height);
	while (i < info->height)
		info->map[i++] = (char *)malloc(sizeof(char) * info->width);
	save_contents(info);
	close(info->fd);
	if (check_error(info))
		return ;
	find_bsq(info);
	reset_contents(info);
}

void	open_stdin(char *file, t_map_info *info)
{
	int	fd;

	fd = open(file, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd == -1)
		info->err = 1;
	info->fd = fd;
}

void	read_from_standard_input(t_map_info *info)
{
	char	c;
	int		j;

	j = 0;
	open_stdin("stdin", info);
	while (read(0, &c, 1) > 0)
	{
		write(info->fd, &c, 1);
	}
	read_from_arguments("stdin", info);
	open("stdin", O_TRUNC);
}
