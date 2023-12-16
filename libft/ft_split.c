/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deordone <deordone@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:50:02 by deordone          #+#    #+#             */
/*   Updated: 2023/10/07 12:35:08 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_howmwords(const char *s, char c)
{
	int		i;
	int		word;
	int		count;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count = 0;
		else if (count == 0)
		{
			count = 1;
			word++;
		}
		i++;
	}
	return (word);
}

void	ft_free_array(char **res, int i)
{
	while (i--)
	{
		free(res[i]);
	}
	free(res);
}

char	**ft_create(char const *s, char c, char **res)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (i > 0 && s[i] != c && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			res[j] = ft_substr(s, start, i - start + 1);
			if (!res[j])
			{
				ft_free_array(res, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**rslt;

	rslt = malloc(sizeof(char *) * (ft_howmwords(s, c) + 1));
	if (!rslt)
		return (NULL);
	rslt = ft_create(s, c, rslt);
	return (rslt);
}
