/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:43:39 by mokariou          #+#    #+#             */
/*   Updated: 2024/11/01 19:26:38 by mokariou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_character(char c)
{
	if (c != 'P' && c != '1' && c != 'C' && c != '0' && c != 'E')
	{
		ft_printf("woopwoop, found undefined characters\n");
		return (1);
	}
	return (0);
}

int	checkmap(int fd, char *file)
{
	char	*buffer;
	int		index;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error: file not valid\n"), 1);
	buffer = get_next_line(fd);
	if (!buffer)
		return (0);
	while (buffer != NULL)
	{
		index = 0;
		while (buffer[index] && buffer[index] != '\n')
		{
			if (check_character(buffer[index]) == 1)
				return (free(buffer), close(fd), 1);
			index++;
		}
		free(buffer);
		buffer = get_next_line(fd);
	}
	return (close(fd), 0);
}

int	check_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[0] == '.')
			return (1);
		if (s[i] == '.' && s[i + 1] == 'b'
			&& s[i + 2] == 'e' && s[i + 3] == 'r' && s[i + 4] == '\0')
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	(void) ac;
// 	int		fd;
// 	fd = open(av[1], O_RDONLY);
// 	printf("%d", checkmap(fd));	
// }