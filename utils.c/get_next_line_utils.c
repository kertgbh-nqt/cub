/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:59:42 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/07 03:09:12 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	gnl_check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == 10)
			return (1);
		i++;
	}
	return (0);
}

int	gnl_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*gnl_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	str = (char *)malloc((gnl_len(s1) + gnl_len(s2) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[i] && s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && s2)
	str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}
