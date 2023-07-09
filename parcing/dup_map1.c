/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_map1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:56:15 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/07 22:03:21 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    dup_map1(t_data *data, int len)
{
    int i;

    i = 0;
    data->map2 = (char **)malloc((len + 1) * sizeof(char *));
    if (!data->map2)
        return (ft_print_fd(2, "couldnt allcoate for map2\n"), exit (7));
    while (data->map1[i])
    {
        data->map2[i] = data->map1[i];
        i++;
    }
    data->map2[i] = NULL;
}
