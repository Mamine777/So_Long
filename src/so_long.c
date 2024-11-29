/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:33:51 by mokariou          #+#    #+#             */
/*   Updated: 2024/11/01 19:37:48 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_game(t_data *data)
{
	move_player(data);
	load_img(data);
	read_map(data);
	mlx_key_hook(data->win, ft_action, data);
	mlx_hook(data->win, 17, 0, destroy_all, data);
	mlx_loop(data->init);
}

void	so_long(int fd, t_data *data, char *file)
{
	if (checkmap(fd, file) == 1 || check_angles(fd, file))
	{
		ft_printf("Error: Invalid map!\n");
		exit(1);
	}
	init_map(fd, data, file);
	data->count_move = 0;
	if (map_boundry(data) || !is_game_if(data, fd, file))
	{
		delocate(data);
		ft_printf("Error: Invalid map!\n");
		exit(1);
	}
	data->init = mlx_init();
	if (!data->init)
	{
		delocate(data);
		exit(1);
	}
	data->win = mlx_new_window(data->init, data->map_widt * TILE_SIZE,
			data->map_heit * TILE_SIZE, "so_long");
	ft_game(data);
}

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac == 2)
	{
		if (check_arg(av[1]) == 1)
			return (ft_printf("file needs to be .ber\n"), 1);
		check_arg(av[1]);
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
		{
			ft_printf("Error: file not valid\n");
			return (1);
		}
		so_long(fd, &data, av[1]);
		destroy_all(&data);
	}
}
