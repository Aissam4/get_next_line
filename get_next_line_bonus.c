/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:23:43 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/16 18:52:28 by abarchil         ###   ########.fr       */
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

char	*reminder(char *str)
{
	char	*rst_tab;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[count] && str[count] != '\n')
		count++;
	if (!str[count])
		return (free(str), NULL);
	rst_tab = (char *)malloc(sizeof(char) * (ft_strlen(str) - count + 1));
	if (!rst_tab)
		return (NULL);
	count++;
	while (str[count])
		rst_tab[i++] = str[count++];
	rst_tab[i] = '\0';
	free (str);
	if (ft_strlen(rst_tab) == 0)
		return (free(rst_tab), NULL);
	return (rst_tab);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*s[10000];
	char			*line;
	int				byte;

	byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10000)
		return (NULL);
	while (byte > 0 && !ft_str_search(s[fd]))
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
		s[fd] = ft_strjoin(s[fd], buffer);
	}
	line = put_line(s[fd]);
	s[fd] = reminder(s[fd]);
	return (line);
}
