/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:25:34 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/09 16:26:09 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

static int	string_slayer(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	free_str(char **str, int j)
{
	while (str[j] >= 0)
	{
		free(str[j]);
		j--;
	}
	free (str);
}

static char	**pls_split(char **str, int l, char c, char *s)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < l)
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		str[k] = ft_substr(s, j, i - j);
		if (!str[k])
		{
			free_str(str, k);
			return (NULL);
		}
		k++;
	}
	str[k] = NULL;
	return (str);
}

char	**ft_split(char *s, char c)
{
	char		**bs;
	int			k;
	int			l;

	k = 0;
	if (!s)
		return (NULL);
	l = string_slayer(s, c);
	bs = (char **)malloc((l + 1) * sizeof (char *));
	if (!bs)
		return (0);
	bs = pls_split(bs, l, c, s);
	return (bs);
}