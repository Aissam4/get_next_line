/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:52:45 by abarchil          #+#    #+#             */
/*   Updated: 2021/10/28 00:28:52 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
char 	*ft_strdup(const char *s);
char 	*ft_strjoin(char const *s1, char const *s2);
int 	ft_str_search(char *s);
#endif
