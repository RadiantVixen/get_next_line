/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 20:02:27 by aatki             #+#    #+#             */
/*   Updated: 2022/11/11 00:35:14 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	int		i;

	i = -1;
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	join = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
	{
		free (join);
		return (NULL);
	}
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
		join[ft_strlen(s1) + i] = s2[i];
	join[ft_strlen(s1) + i] = '\0';
	return (join);
}

char	*ft_strdup(char *src)
{
	char	*depliquer;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!src)
		return (NULL);
	while (src[len])
		len++;
	depliquer = (char *)malloc(sizeof (char) * (len + 1));
	if (!depliquer)
		return (0);
	while (src[i])
	{
		depliquer[i] = src[i];
		i++;
	}
	depliquer[i] = '\0';
	return (depliquer);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (0);
	if (start >= (unsigned int) ft_strlen(s))
		return (ft_strdup(0));
	i = 0;
	while (s[start + i] && i < len)
		i++;
	sub = (char *)malloc (sizeof(char) * (i + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

char	*check(char **s)
{
	int		i;
	char	*ret;
	char	*tmp2;
	char	*tmp_s;

	i = 0;
	tmp_s = *s;
	if (!tmp_s)
		return (NULL);
	while (tmp_s[i])
	{
		if (tmp_s[i] == '\n')
		{
			ret = ft_strdup(tmp_s + i + 1);
			tmp2 = ft_substr(tmp_s, 0, i + 1);
			free (*s);
			*s = ft_strdup(tmp2);
			free (tmp2);
			return (ret);
		}
		i++;
	}
	return (NULL);
}
