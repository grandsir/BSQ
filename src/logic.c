/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: databey <databey@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:00:40 by databey           #+#    #+#             */
/*   Updated: 2023/07/29 12:00:42 by databey          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void    find_bsq(t_map_info *info)
{
    int i;
    int j;
    int dp[info->height][info->width];

    i = 0;
    j = 0;
    while (i < info->height)
       fill_with_zeros(dp[i++], info);
    i = 0;

    while (i < info->height)
    {
        while(j <= info->width) 
        {
            j++;
            if(info->map[i][j] == info->obstacle)
            {
                dp[i][j] = 0;
            } 
            else {
                dp[i][j] = find_min(dp[i][cr(j - 1)], dp[cr(i - 1)][j], dp[cr(i - 1)][cr(j - 1)]);
            }
        }
        i++;
    }
    j = 0;
    while (j < info->height) {
        for (int i = 0; i <= info->width; i++)
            printf("%d", dp[j][i]);
        j++;
        printf("\n");
    }
 
}

int find_min(int left, int top, int topLeft)
{
    int arr[3];
    int i;
    int min;

    min = left;
    i = 0;
    arr[0] = left;
    arr[1] = top;
    arr[2] = topLeft;
    while (i < 3)
    {
        if (arr[i] < min)
            min = arr[i];
        i++;
    }
    return (min + 1);
}


void    fill_with_zeros(int dp[], t_map_info *info)
{
    int     i;

    i = 0;
    while (i <= info->width)
        dp[i++] = 0;
}