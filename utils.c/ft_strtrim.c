/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:45:05 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/07 22:51:11 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char	*ft_strdup(char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc ((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char	*s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if ((int)start > ft_strlen(s))
		return (ft_strdup(""));
	new = (char *)malloc((len + 1) * sizeof (char));
	if (!new)
		return (NULL);
	while (i < len && s[start + i])
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static int	checker(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	head(char *s1, char *set)
{
	int	i;

	i = 0;
	while (s1[i] && checker (s1[i], set) == 1)
		i++;
	return (i);
}

static int	tail(char *s1, char *set)
{
	int	i;

	i = ft_strlen (s1) - 1;
	while (i >= 0 && checker(s1[i], set) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char *s1, char *set)
{
	int	start;
	int	end;
	int	len;

	if (!s1 || !set)
		return (NULL);
	start = head (s1, set);
	end = tail (s1, set);
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}