/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_angles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:27:38 by mokariou          #+#    #+#             */
/*   Updated: 2024/11/01 19:38:03 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_angles(int fd, char *file)
{
	int		width;
	char	*buffer;
	int		length_current;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: file not valid\n"), 1);
	buffer = get_next_line(fd);
	if (!buffer)
		return (1);
	width = ft_strlen(buffer);
	if (buffer[width - 1] == '\n')
		width -= 1;
	while (buffer != NULL)
	{
		length_current = ft_strlen(buffer);
		if (buffer[length_current - 1] == '\n')
			length_current -= 1;
		if (width != length_current)
			return (free(buffer), close(fd), 1);
		length_current = 0;
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (close(fd), 0);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	(void) ac;
	int	fd = open(av[1], O_RDONLY);
	printf ("%d", check_angles(fd));
}*/