/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:11:59 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/06 12:34:24 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char	*buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i + (buf[i] == '\n'));
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*res;
	int			size;
	int			bytes_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	res = ft_calloc(1, 1);
	if (!buf)
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (buf && res)
	{
		// size = check_line(res);
		bytes_read = read(fd, buf, BUFFER_SIZE);
		res = ft_strjoin(res, buf);
		buf[bytes_read] = '\0';
		if (bytes_read < 1)
		{
			if (ft_strlen(res) > 0)
				return (res);
			free(buf);
			buf = NULL;
			return (NULL);
		}
		else if (bytes_read >= 1)
			return (res);
	}
	return (NULL);
}

#include <unistd.h>
void	ft_putstr(char	*str){if (str == NULL){return ;}int i = 0;while(str[i]){write(1, &str[i], 1);i++;}}
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	char	*ln;
	int		fd;
	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		ln = get_next_line(fd);
		if (ln == NULL)
			return (0);
		ft_putstr(ln);
		free(ln);
	}
}
