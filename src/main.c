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
        map_invalid_error();
}


/*
void    save_contents(t_map_info info)
{
    int     r;
    char    c;
    int     i;
    int     j;

    j = 0;
    i = 0;
    info.map = malloc(sizeof(*info.map) * info.height);
    while((r = read(info.fd, &c, 1)))
    {
        if (i == 0)
            info.map[i] = malloc(sizeof(char) * info.width);

        info.map[i][j] = c;
        if (info.width - 1 == j)
        {
            info.map[++i] = malloc(sizeof(char) * info.width);
            j = 0;
            continue ;    
        }
        j++;
    }
}
*/
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
            j = 0;
            i++;
            continue;
        }

        if (i > 0) {
            info->map[i - 1][j] = c;
        }

        j++;
    }
    
}

int	    main(int argc, char **argv)
{
    t_map_info  info;
    int         i;

    i = 0;
    if (argc > 1)
    {
        open_file(&info ,argv[1]);
        parse_params(&info);
        close(info.fd);
        open_file(&info ,argv[1]);
        i = 0;
        info.map = (char **)malloc(sizeof(char *) * info.height);
		while (i < info.height)
			info.map[i++] = (char *)malloc(sizeof(char) * info.width);
        save_contents(&info);
        close(info.fd);
    }
    print_map_info(&info);
    find_bsq(&info);
}
