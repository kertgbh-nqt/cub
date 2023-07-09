/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:25:46 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/09 15:26:06 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_atoi(char *str)
{
	int				i;
	long long		signe;
	unsigned long	result;

	result = 0;
	i = 0;
	signe = 1;
	while (((str[i] >= 9) && (str[i] <= 13)) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0' && str [i])
	{
		result = (result * 10) + (str[i] - 48);
		i++;
		if (result > 9223372036854775807 && signe == 1)
			return (-1);
		else if (result > 9223372036854775807 && signe == -1)
			return (0);
	}
	return (result * signe);
}