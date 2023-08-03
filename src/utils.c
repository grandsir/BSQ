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

int	ft_map_atoi(char *str, t_map_info *info)
{
	int	value;
	int	i;

	value = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		value = (value * 10) + (str[i++] - '0');
	if (ft_strlen(str) - i != 4)
		info->err = 1;
	if (str[i + 2] == str[i + 1] || str[i + 2] == str[i] || 
		str[i + 1] == str[i])
		info->err = 1;
	info->fill = str[i + 2];
	info->obstacle = str[i + 1];
	info->empty = str[i];
	return (value);
}

int	cr(int val)
{
	if (val > 0)
		return (val);
	else
		return (0);
}
