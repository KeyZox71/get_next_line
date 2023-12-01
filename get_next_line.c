/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:11:59 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/01 23:03:24 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char	*buf)
{
	int	i;

	i = 0;
	while (buf[i] || buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

void	read_line(int fd, char *buf)
{
	char	*tmp;
	size_t	read_nb;

	while (!check_line(buf) && read_nb != 0)
	{
		tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!tmp)
		{
			buf = NULL;
			return ;
		}
		read_nb = read(fd, tmp, BUFFER_SIZE);
		buf = ft_strjoin(buf, tmp);
		free(tmp);
	}
}

char	*line_to_str(char *buf)
{
	char	*res;
	size_t	i;
	size_t	size_buf;

	i = 0;
	size_buf = ft_strlen_til_nl(buf);
	res = malloc((size_buf + 1) * sizeof(char));
	while (i < size_buf)
	{
		res[i] = buf[i];
		if (buf[i] == '\n')
			break ;
		i++;
	}
	free (buf);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*res;

	if (BUFFER_SIZE <= 0 || read(fd, &res, 0) < 0 || fd < 0)
		return (NULL);
	read_line(fd, buf);
	res = line_to_str(buf);
	return (res);
}

#include <unistd.h>
void	ft_putstr(char	*str){if (str == NULL){return ;}int i = 0;while(str[i]){write(1, &str[i], 1);i++;}}
#include <fcntl.h>
int	main(void)
{
	char	*ln;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		ln = get_next_line(fd);
		if (ln == NULL)
			break ;
		ft_putstr(ln);
		free(ln);
	}
}
