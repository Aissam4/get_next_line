/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:29:07 by abarchil          #+#    #+#             */
/*   Updated: 2021/10/28 00:30:27 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;
	size_t	count;

	dest1 = (char *)dest;
	src1 = (char *)src;
	count = 0;
	if (!dest && !src)
		return (NULL);
	if (dest1 < src1)
	{
	while (count < n)
		{
			dest1[count] = src1[count];
			count++;
		}
	}
	else
	{
		while (n-- > 0)
			dest1[n] = src1[n];
	}
	return (dest1);
}

int	ft_str_search(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
	{
		if (s[count] == '\n')
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*src;
	int		count;
	int		s_len;

	count = 0;
	src = (char *)s;
	s_len = ft_strlen(src);
	dest = (char *)malloc(sizeof(const char) * s_len + 1);
	if (!dest)
		return (NULL);
	while (count < s_len)
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result_tab;
	unsigned int	total_len;
	unsigned int	s1_count;
	unsigned int	s2_count;

	s1_count = 0;
	s2_count = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result_tab = (char *)malloc(sizeof(char) * total_len + 1);
	if (!result_tab)
		return (NULL);
	ft_memmove(result_tab, s1, ft_strlen(s1));
	ft_memmove(result_tab + ft_strlen(s1), s2, ft_strlen(s2));
	result_tab[total_len] = '\0';
	free((char *)s1);
	return (result_tab);
}
