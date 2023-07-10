/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:51:04 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/10 02:00:51 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	is_in_wrong_place(int i, int j, char **str)
{
	if (str[i + 1][j] && str[i + 1][j] == ' ')
		return (1);
	if (str[i - 1][j] && str[i - 1][j] == ' ')
		return (1);
	if (str[i][j + 1] && str[i][j + 1] == ' ')
		return (1);
	if (str[i][j - 1] && str[i][j - 1] == ' ')
		return (1);
	return (0);
}

int	norm(char *str, int i, char c)
{
	if (str[i] == c && str[i + 1] == ' ')
		return (1);
	return (0);
}
