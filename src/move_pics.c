/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:24:09 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/31 19:33:31 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_data *data)
{
	data->player_left = mlx_xpm_file_to_image
		(data->init, "img/npcleftmv.xpm",
			&data->widt_img, &data->heit_img);
	data->player_right = mlx_xpm_file_to_image
		(data->init, "img/npcrightmv.xpm",
			&data->widt_img, &data->heit_img);
	data->player_forward = mlx_xpm_file_to_image
		(data->init, "img/npc.xpm", &data->widt_img, &data->heit_img);
	data->player_backword = mlx_xpm_file_to_image
		(data->init, "img/npcback.xpm", &data->widt_img, &data->heit_img);
}
