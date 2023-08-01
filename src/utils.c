/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 11:56:47 by databey           #+#    #+#             */
/*   Updated: 2023/07/29 11:23:07 by databey          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_map_atoi(char *str, t_map_info *info)
{
	int		value;
	int		i;

	value = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		value = (value * 10) + (str[i++] - '0');
	info->fill = str[i + 2];
	info->obstacle = str[i + 1];
	info->empty = str[i];
	return (value);
}

void print_map_info(const t_map_info *map_info)
{
    printf("Map Information:\n");
    printf("  Width: %d\n", map_info->width);
    printf("  Height: %d\n", map_info->height);
    printf("  Obstacle: '%c'\n", map_info->obstacle);
    printf("  Empty: '%c'\n", map_info->empty);
    printf("  Fill: '%c'\n", map_info->fill);
    printf("  File Descriptor: %d\n", map_info->fd);

    printf("  Map:\n");
    for (int i = 0; i < map_info->height; i++)
    {
        printf("  ");
        for (int j = 0; j <= map_info->width; j++)
        {
            printf("%c", map_info->map[i][j]);
        }
        printf("\n");
    }
}