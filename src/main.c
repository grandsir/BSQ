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
#include <stdio.h>

int     save_contents_of_file(t_map_info *info, char *file)
{
    int fd;

    if ((fd = open(file, 0)) == -1)
        return (0);
    info->fd = fd;
    return (1);
}

void     parse_params(t_map_info *info)
{
    int     j;
    int     i;
    int     r;
    char    c;
    char    height_info[500];

    while((r = read(info->fd, &c, 1)))
    {
        if (i == 0)
            height_info[j++] = c;
        if (i == 1 && c != '\n')
            info->width += 1;
        if (i == 2)
            break;
        if (c == '\n')
            i++;
    }

    info->height = ft_map_atoi(height_info[j], info);

    if (!info->height)
    {
        map_invalid_error();
    }
}

int	    main(int argc, char **argv)
{
    t_map_info  info;

    if (argc > 1) {
        save_contents_of_file(&info ,argv[1]);
        parse_params(&info);
        close(info.fd);
    }
}