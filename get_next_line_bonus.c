/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:23:43 by abarchil          #+#    #+#             */
/*   Updated: 2021/11/15 19:28:26 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_line(char *str)
{
	char 	*rst_tab;
	int	count;

	count = 0;
	if (!str)
		return (NULL);
	while(str[count] && str[count] != '\n')
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
	int	count;
	int	i;
	
	count = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[count] && str[count] != '\n')
		count++;
	if (!str[count])
	{
		free(str);
		str = NULL;
		return (0);
	}
	rst_tab = (char *)malloc(sizeof(char) * (ft_strlen(str) - count + 1));
	if (!rst_tab)
		return (NULL);
	count++;
	while (str[count])
	{
		rst_tab[i] = str[count];
		i++;
		count++;
	}
	rst_tab[i] = '\0';
	free (str);
	return (rst_tab);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static	char	*s;
	char	*line;
	int		byte;

	byte = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	while (byte > 0 && !ft_str_search(s))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (byte == 0)
		{
			buffer[byte] = '\0';
			break;
		}
		buffer[byte] = '\0';
		s = ft_strjoin(s, buffer);
	}
	free(buffer);
	line = put_line(s);
	s = reminder(s);
	return (line);
}
// int main(void)
// {
// 	int fd;
// 	fd = open ("txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
