/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:31:12 by mokariou          #+#    #+#             */
/*   Updated: 2024/10/31 18:32:41 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*count dimensions of the map: I calculate the width of the line and then 
I set the hight of the map*/

#include "../so_long.h"

void	count_dimensions(int fd, t_data *data, char *file)
{
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("failed to open\n");
		return ;
	}
	buffer = get_next_line(fd);
	if (!buffer)
		return ;
	if (buffer[ft_strlen(buffer) - 1] == '\n')
		data->map_widt = ft_strlen(buffer) - 1;
	else
		data->map_widt = ft_strlen(buffer);
	data->map_heit = 0;
	while (buffer != NULL && buffer[0] != '\0')
	{
		data->map_heit++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	close(fd);
}
/*I locate memory of the map[width][height]*/

void	locate_memory(t_data *data)
{
	int	i;

	data->map = (char **)malloc(sizeof(char *) * (data->map_heit));
	if (!data->map)
	{
		ft_printf("memory allocation failed in init_map!");
		return ;
	}
	i = 0;
	while (i < data->map_heit)
	{
		data->map[i] = (char *)malloc(sizeof(char) * (data->map_widt + 1));
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

void	fill_map(int fd, t_data *data, char *file)
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
	while (buffer != NULL && buffer[0] != '\0')
	{
		ft_strlcpy(data->map[i], buffer, data->map_widt + 1);
		i++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
}

void	init_map(int fd, t_data *data, char *file)
{
	count_dimensions(fd, data, file);
	locate_memory(data);
	fill_map(fd, data, file);
}
