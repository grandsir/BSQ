#ifndef BSQ_H
# define BSQ_H

#include <fcntl.h>

typedef struct s_map_data
{
    int     width;
    int     height;
    int     fd;
} t_map_info;

void	ft_putchar(char);
void	ft_putstr(char *str);

#endif