/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aatki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:01:17 by aatki             #+#    #+#             */
/*   Updated: 2022/11/11 00:31:52 by aatki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	init_get_next_line(char **string, char \
		**tmp_string, char **tmp, char **s)
{
	*string = NULL;
	*tmp_string = NULL;
	*tmp = NULL;
	if (*s)
	{
		*string = ft_strjoin(*string, *s);
		free(*s);
		*s = NULL;
	}
	*tmp = malloc(BUFFER_SIZE + 1);
	if (!*tmp)
	{
		free (*string);
		return (0);
	}
	return (1);
}

char	*end_get_next_line(char **tmp, char **s, char **string)
{
	free(*tmp);
	*s = check(string);
	if (*string[0] == '\0')
	{
		free (*string);
		*string = NULL;
		free (*s);
		*s = NULL;
	}
	return (*string);
}

void	ft_remove_leaks(char **tmp_string, char **string, char **tmp)
{
	*tmp_string = ft_strjoin(*string, *tmp);
	free (*string);
	*string = ft_strdup(*tmp_string);
	free (*tmp_string);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*string;
	char		*tmp;
	int			readed;
	char		*tmp_string;

	if (fd < 0 || BUFFER_SIZE <= 0 || \
			!init_get_next_line(&string, &tmp_string, &tmp, &s))
		return (NULL);
	readed = 1;
	while (new_line(string) && readed)
	{
		readed = read(fd, tmp, BUFFER_SIZE);
		if (readed == -1)
		{
			free (tmp);
			free (string);
			return (0);
		}
		tmp[readed] = '\0';
		ft_remove_leaks(&tmp_string, &string, &tmp);
	}
	return (end_get_next_line(&tmp, &s, &string));
}
