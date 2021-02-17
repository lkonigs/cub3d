/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <lkonig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 17:44:11 by lkonig            #+#    #+#             */
/*   Updated: 2020/05/26 11:42:38 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				endline(char *alreadyread)
{
	int			len;

	if (!alreadyread)
		return (-1);
	len = 0;
	while (alreadyread[len] != '\0')
	{
		if (alreadyread[len] == '\n')
			return (len);
		len++;
	}
	return (-1);
}

char			*fillread(int moretoread, char *buf, char *alreadyread)
{
	char		*tmp;

	tmp = NULL;
	buf[moretoread] = '\0';
	if (alreadyread == NULL)
	{
		alreadyread = ft_strdup(buf);
	}
	else
	{
		tmp = alreadyread;
		alreadyread = ft_strjoin(alreadyread, buf);
		ft_free(tmp);
	}
	return (alreadyread);
}

char			*emptyread(char **line, char *alreadyread, int len)
{
	char		*tmp;

	tmp = alreadyread;
	*line = ft_substr(alreadyread, 0, len);
	alreadyread = ft_substr(alreadyread, len + 1, ft_strlen(alreadyread));
	ft_free(tmp);
	return (alreadyread);
}

int				erreur(char *alreadyread)
{
	ft_free(alreadyread);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	int			moretoread;
	int			len;
	char		buf[BUFFER_SIZE + 1];
	static char	*alreadyread = NULL;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	moretoread = 0;
	while ((endline(alreadyread) < 0)
		&& ((moretoread = read(fd, buf, BUFFER_SIZE)) > 0))
		alreadyread = fillread(moretoread, buf, alreadyread);
	if (moretoread < 0)
		return (erreur(alreadyread));
	if ((len = endline(alreadyread)) >= 0)
	{
		alreadyread = emptyread(line, alreadyread, len);
		return (1);
	}
	else
	{
		alreadyread = fillread(moretoread, buf, alreadyread);
		*line = ft_strjoin(alreadyread, buf);
	}
	ft_free(alreadyread);
	return (0);
}
