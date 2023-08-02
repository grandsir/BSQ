/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:23:20 by databey           #+#    #+#             */
/*   Updated: 2023/08/02 17:17:19 by databey          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map_data
{
	int		width;
	int		height;
	char	obstacle;
	char	empty;
	char	fill;
	int		fd;
	char	**map;
	int		x;
	int		y;
	int		err;
}			t_map_info;

void		map_invalid_error(t_map_info *info);
void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_map_atoi(char *str, t_map_info *info);
void		find_bsq(t_map_info *info);
void		reset_contents(t_map_info *info);
void		print_map_info(const t_map_info *info);
void		fill_with_zeros(int dp[], t_map_info *info);
int			check_square_x(t_map_info *info, int i, int j, int max);
void		read_from_arguments(char *file, t_map_info *info);
void		print_map_with_square(t_map_info *info, int height, int width,
				int **dp);
void		read_from_standard_input(t_map_info *info);
void		save_contents(t_map_info *info);
void		parse_params(t_map_info *info);
void		open_file(t_map_info *info, char *file);
int			find_min(int left, int top, int topLeft);
int			ft_strlen(char *s);
int			cr(int val);
void		change_info(t_map_info *info, int i, int j);

#endif
