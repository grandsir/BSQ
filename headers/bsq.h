/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:23:20 by databey           #+#    #+#             */
/*   Updated: 2023/07/29 11:23:22 by databey          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

#include <fcntl.h>
#include <unistd.h>

typedef struct s_map_data
{
    int     width;
    int     height;
    char    obstacle;
    char    empty;
    char    fill;
    int     fd;
} t_map_info;

void    map_invalid_error(void);
void	ft_putchar(char);
void	ft_putstr(char *str);
int		ft_map_atoi(char*, t_map_info*);

#endif
