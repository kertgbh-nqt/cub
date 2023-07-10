/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:33:16 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/10 01:18:30 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

// check name if it's long enough to handle .cub then see if it end with .cub
// check if we have access to it

void	ft_check_name(char *str)
{
	int		len;
	int		fd;
	int		red;
	char	buff[1];

	len = ft_strlen(str) - 1;
	if (len <= 3)
		return (ft_print_fd(2, "short :')\n"), exit(3));
	if (str[len] != 'b' || str[len - 1] != 'u' || str[len - 2] != 'c'
		|| str[len - 3] != '.')
		return (ft_print_fd(2, "your map doesn't last with .cub\n"), exit(4));
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_print_fd(2, "can't open/find your .cub map\n"),
			(void)close(fd), exit(5));
	red = read(fd, buff, 1);
	if (red == -1)
		return (ft_print_fd(2, "your file is a directory ? \n"),
			(void)close(fd), exit(6));
	if (red == 0)
		return (ft_print_fd(2, "empty file\n"), (void)close(fd), exit(63));
	close(fd);
}
