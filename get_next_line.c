/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:23:43 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/16 18:49:42 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_line(char *str)
{
	char	*rst_tab;
	int		count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count] && str[count] != '\n')
		count++;
	count += 1;
	rst_tab = (char *)malloc(sizeof(char) * count + 1);
	if (!rst_tab)
		return (NULL);
	ft_memmove(rst_tab, str, count);
	rst_tab[count] = '\0';
	return (rst_tab);
}

char	*ft_get_remainder(char *str)
{
	char	*rst_tab;
	int		count;
	int		len;

	count = 0;
	len = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[count] && str[count] != '\n')
		count++;
	if (!str[count])
	{
		free(str);
		return (0);
	}
	rst_tab = (char *)malloc(sizeof(char) * len - count);
	if (!rst_tab)
		return (NULL);
	count++;
	ft_memmove(rst_tab, str + count, len - count);
	rst_tab[len - count] = '\0';
	free (str);
	if (ft_strlen(rst_tab) == 0)
		return (free(rst_tab), NULL);
	return (rst_tab);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*s;
	char			*line;
	int				byte;

	byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (byte != 0 && !ft_str_search(s))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (NULL);
		if (byte == 0)
		{
			buffer[byte] = '\0';
			break ;
		}
		buffer[byte] = '\0';
		s = ft_strjoin(s, buffer);
	}
	line = put_line(s);
	s = ft_get_remainder(s);
	return (line);
}
