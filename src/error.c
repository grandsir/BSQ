/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:54:44 by databey           #+#    #+#             */
/*   Updated: 2023/07/29 12:54:47 by databey          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	map_invalid_error(t_map_info *info)
{
	write(2, "map error\n", 10);
	reset_contents(info);
}
