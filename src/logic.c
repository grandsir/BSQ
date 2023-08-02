/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:00:40 by databey           #+#    #+#             */
/*   Updated: 2023/08/02 17:16:20 by databey          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_bsq(t_map_info *info, int **dp, int *max)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			if (info->map[i][j] == info->obstacle)
				dp[i][j] = 0;
			else
			{
				dp[i][j] = find_min(dp[i][cr(j - 1)], dp[cr(i - 1)][j], 
						dp[cr(i - 1)][cr(j - 1)]);
				if (dp[i][j] > *max)
				{
					*max = dp[i][j];
					change_info(info, i, j);
				}
			}
			j++;
		}
		i++;
	}
}

void	find_bsq(t_map_info *info)
{
	int	i;
	int	j;
	int	k;
	int	max;
	int	**dp;

	i = 0;
	j = 0;
	k = 0;
	max = 0;
	dp = (int **)malloc(info->height * sizeof(int *));
	while (k < info->height)
		dp[k++] = (int *)malloc(info->width * sizeof(int));
	while (i < info->height)
		fill_with_zeros(dp[i++], info);
	print_bsq(info, dp, &max);
	print_map_with_square(info, info->height, info->width, dp);
}

void	print_map_with_square(t_map_info *info, int height, int width, int **dp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (check_square_x(info, i, j, dp[info->x][info->y]))
				ft_putchar(info->fill);
			else
				ft_putchar(info->map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int	check_square_x(t_map_info *info, int i, int j, int max)
{
	int	a;
	int	b;

	a = info->x - (max - 1);
	b = info->y - (max - 1);
	return ((i >= a && i <= info->x) && (j >= b && j <= info->y));
}

void	fill_with_zeros(int dp[], t_map_info *info)
{
	int	i;

	i = 0;
	while (i <= info->width)
		dp[i++] = 0;
}
