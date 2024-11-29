/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_boundry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:12:55 by mokariou          #+#    #+#             */
/*   Updated: 2024/11/01 19:37:05 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_widt)
	{
		if (data->map[0][i] != '1' || data->map[data->map_heit - 1][i] != '1')
			return (1);
		i++;
	}
	j = 0;
	while (j < data->map_heit)
	{
		if (data->map[j][0] != '1' || data->map[j][data->map_widt - 1] != '1')
			return (1);
		j++;
	}
	return (0);
}

void	check_p_e_c2(t_data *data, int *c_coin, int *c_exit, int *c_player)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_heit)
	{
		j = -1;
		while (++j < data->map_widt)
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				(*c_player)++;
			}
			if (data->map[i][j] == 'E')
				(*c_exit)++;
			if (data->map[i][j] == 'C')
			{
				data->total_coin++;
				(*c_coin)++;
			}
		}
	}
}

static int	check_p_e_c(t_data *data)
{
	int	count_pla;
	int	count_exit;
	int	count_coin;

	count_pla = 0;
	count_exit = 0;
	count_coin = 0;
	check_p_e_c2(data, &count_coin, &count_exit, &count_pla);
	if (count_pla != 1)
	{
		ft_printf("Error:must contain exactly 1 player.Found %d.\n", count_pla);
		return (1);
	}
	if (count_exit != 1)
	{
		ft_printf("Error: must contain exactly 1 exit.Found %d.\n", count_exit);
		return (1);
	}
	if (count_coin == 0)
	{
		ft_printf("Error: Map must contain at least 1 (C).\n");
		return (1);
	}
	return (0);
}

int	map_boundry(t_data *data)
{
	data->total_coin = 0;
	data->collected_coin = 0;
	if (check_walls(data) == 1 || check_p_e_c(data) == 1)
		return (1);
	return (0);
}
