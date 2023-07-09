/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:36:10 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/07 21:42:48 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int ft_gnl_size(char *str)
{
    int fd;
    int i;
    char *buff;

    i = 0;
    fd = open(str, O_RDONLY);
    while (1)
    {
        buff = get_next_line(fd);
        if (buff == NULL)
            break;
        i++;
        free(buff);        
    }
    close (fd);
    return (i);
}

