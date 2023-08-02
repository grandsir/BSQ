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

int     open_file(t_map_info *info, char *file)
{
    int fd;
    fd = open(file, 0);
    if (fd == -1)
        info->err = 1;
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

    i = 0;
    j = 0;
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

    info->height = ft_map_atoi(height_info, info);

    if (!info->height)
        info->err = 1;
}

void    save_contents(t_map_info *info) {
    char    c;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while(read(info->fd, &c, 1) > 0)
    {
        if(c == '\n')
        {
            if (i > 0 && j != info->width)
                info->err = 1;
            j = 0;
            i++;
            continue;
        }
        if (i > 0) {
            if (c != info->obstacle && c != info->empty) {
                info->err = 1;
            }
            info->map[i - 1][j] = c;
        }
        j++;
    }
}

void    read_from_arguments(int *i, char *file, t_map_info *info)
{
        open_file(info, file);
        parse_params(info);
        open_file(info, file);
        *i = 0;
        info->map = (char **)malloc(sizeof(char *) * info->height);
		while (*i < info->height)
			info->map[(*i)++] = (char *)malloc(sizeof(char) * info->width);
        save_contents(info);
        close(info->fd);
        if (info->err)
        {
            map_invalid_error(info);        
            return;
        } 
        find_bsq(info);
        reset_contents(info);
        ft_putchar('\n');
}

int	    main(int argc, char **argv)
{
    t_map_info  info;
    int         i;
    int         j;

    i = 0;
    j = 0;
    while (argc > ++j)
    {
        read_from_arguments(&i, argv[j], &info);
    }
}
