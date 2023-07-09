/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:59:49 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/07 03:09:46 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char	*gnl_stock(char *str)
{
	char	*str_stock;
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (str[i] && str[i] != 10)
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	str_stock = (char *)malloc((gnl_len(str) + 1) * sizeof(char));
	if (!str_stock)
		return (0);
	if (str[i] == '\n')
		i++;
	while (str[i])
		str_stock[c++] = str[i++];
	str_stock[c] = '\0';
	free(str);
	return (str_stock);
}

char	*gnl_ret(char *str)
{
	char	*str_ret;
	int		i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != 10)
		i++;
	if (str[i] == '\n')
		i++;
	str_ret = (char *)malloc((i + 1) * sizeof(char));
	if (!str_ret)
		return (0);
	i = 0;
	while (str[i] && str[i] != 10)
	{
		str_ret[i] = str[i];
		i++;
	}
	if (str[i] == 10)
		str_ret[i++] = 10;
	str_ret[i] = 0;
	return (str_ret);
}

char	*big_n(int fd, char *s)
{
	char	*buff;
	int		roderer;

	buff = (char *)malloc(BUFFER_SIZE + (1 * sizeof(char)));
	if (!buff)
		return (0);
	roderer = 19;
	while (!gnl_check(s) && roderer)
	{
		roderer = read(fd, buff, BUFFER_SIZE);
		if (roderer == -1)
		{
			free(buff);
			free(s);
			return (NULL);
		}
		buff[roderer] = '\0';
		s = gnl_join(s, buff);
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*stick;
	char		*str_ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stick = big_n(fd, stick);
	if (!stick)
		return (0);
	str_ret = gnl_ret(stick);
	stick = gnl_stock(stick);
	return (str_ret);
}
