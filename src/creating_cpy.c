/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:50:51 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/31 18:21:21 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_cpy(char **map, int height)
{
	int	str;

	str = 0;
	while (str < height)
	{
		free(map[str]);
		str++;
	}
	free(map);
}
/*I locate memory of the map[width][height]*/

static void	memory(t_data *data)
{
	int	i;

	data->cp_mp = (char **)malloc(sizeof(char *) * (data->map_heit));
	if (!data->map)
	{
		ft_printf("memory allocation failed in init_map!");
		return ;
	}
	i = 0;
	while (i < data->map_heit)
	{
		data->cp_mp[i] = (char *)malloc(sizeof(char) * (data->map_widt + 1));
		if (!data->map[i])
		{
			delocate(data);
			ft_printf("memory allocation failed in init_map!\n");
			return ;
		}
		i++;
	}
}
/* i fill the **map of tha data I read*/

static void	fill(int fd, t_data *data, char *file)
{
	char	*buffer;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("failed to open\n");
		return ;
	}
	buffer = get_next_line(fd);
	if (!buffer)
	{
		close(fd);
		return ;
	}
	i = 0;
	while (buffer != NULL)
	{
		ft_strlcpy(data->cp_mp[i], buffer, data->map_widt + 1);
		i++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
}

void	init_copy(int fd, t_data *data, char *file)
{
	memory(data);
	fill(fd, data, file);
}
