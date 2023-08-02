/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:48:01 by databey           #+#    #+#             */
/*   Updated: 2023/08/01 18:48:03 by databey          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	find_min(int left, int top, int topLeft)
{
	int	arr[3];
	int	i;
	int	min;

	min = left;
	i = 0;
	arr[0] = left;
	arr[1] = top;
	arr[2] = topLeft;
	while (i < 3)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min + 1);
}

void	change_info(t_map_info *info, int i, int j)
{
	info->x = i;
	info->y = j;
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	reset_contents(t_map_info *info)
{
	info->width = 0;
	info->height = 0;
	info->fd = 0;
	info->err = 0;
}
