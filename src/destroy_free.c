/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:02:26 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/31 18:01:50 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	delocate(t_data *data)
{
	int	str;

	str = 0;
	while (str < data->map_heit)
	{
		free(data->map[str]);
		str++;
	}
	free(data->map);
}

void	destroy_img(t_data *data)
{
	if (data->player_left)
		mlx_destroy_image(data->init, data->player_left);
	if (data->player_forward)
		mlx_destroy_image(data->init, data->player_forward);
	if (data->player_right)
		mlx_destroy_image(data->init, data->player_right);
	if (data->player_backword)
		mlx_destroy_image(data->init, data->player_backword);
	if (data->img_empty)
		mlx_destroy_image(data->init, data->img_empty);
	if (data->img_bush)
		mlx_destroy_image(data->init, data->img_bush);
	if (data->img_exit)
		mlx_destroy_image(data->init, data->img_exit);
	if (data->img_coin)
		mlx_destroy_image(data->init, data->img_coin);
}

int	destroy_all(t_data *data)
{
	destroy_img(data);
	delocate(data);
	mlx_destroy_window(data->init, data->win);
	free(data->init);
	exit(0);
}
