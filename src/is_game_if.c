/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_game_if.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:26:38 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/31 17:52:32 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	find_collected(t_data *data, int y, int x, int *collected)
{
	if (y < 0 || x < 0 || data->cp_mp[y] == NULL || data->cp_mp[y][x] == '1' ||
	data->cp_mp[y][x] == '+' || data->cp_mp[y][x] == 'E')
		return (0);
	if (data->cp_mp[y][x] == 'C')
		(*collected)--;
	if (*collected == 0)
		return (1);
	data->cp_mp[y][x] = '+';
	if (find_collected(data, y + 1, x, collected))
		return (1);
	if (find_collected(data, y - 1, x, collected))
		return (1);
	if (find_collected(data, y, x + 1, collected))
		return (1);
	if (find_collected(data, y, x - 1, collected))
		return (1);
	return (0);
}

static int	find_exit(char **cp_mp, int y, int x)
{
	if (y < 0 || x < 0 || cp_mp[y] == NULL
		|| cp_mp[y][x] == '1' || cp_mp[y][x] == '+')
		return (0);
	if (cp_mp[y][x] == 'E')
		return (1);
	cp_mp[y][x] = '+';
	if (find_exit(cp_mp, y, x + 1))
		return (1);
	if (find_exit(cp_mp, y, x - 1))
		return (1);
	if (find_exit(cp_mp, y + 1, x))
		return (1);
	if (find_exit(cp_mp, y - 1, x))
		return (1);
	return (0);
}

int	is_game_if(t_data *data, int fd, char *file)
{
	int		collected;
	int		exit_piece;

	collected = data->total_coin;
	init_copy(fd, data, file);
	if (!data->cp_mp)
		return (0);
	find_collected(data, data->player_y, data->player_x, &collected);
	free_cpy(data->cp_mp, data->map_heit);
	init_copy(fd, data, file);
	if (!data->cp_mp)
		return (0);
	exit_piece = find_exit(data->cp_mp, data->player_y, data->player_x);
	free_cpy(data->cp_mp, data->map_heit);
	if (collected == 0 && exit_piece)
		return (1);
	return (0);
}
