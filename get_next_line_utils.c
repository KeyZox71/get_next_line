/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adjoly <adjoly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:12:02 by adjoly            #+#    #+#             */
/*   Updated: 2023/12/08 11:17:51 by adjoly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*size_t	ft_strlen_til_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}*/

char	*ft_strljoin(char *s1, char *s2, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	result = ft_calloc((ft_strlen(s1) + len + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] || j < len)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	result[i] = '\0';
	return (result);
}

size_t	ft_strlcpy(char	*dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (ft_strlen(src));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*result;

	if (size != 0 && nmemb != 0 && (nmemb * size) / nmemb != size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	result = malloc(size * nmemb);
	if (result == NULL)
		return (NULL);
	while (i < size * nmemb)
	{
		*(unsigned char *)(result + i) = '\0';
		i++;
	}
	return (result);
}
