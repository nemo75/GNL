/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skynet <skynet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 02:18:39 by thbricqu          #+#    #+#             */
/*   Updated: 2016/12/03 18:35:56 by skynet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static size_t ft_strlchr(char *str,size_t index, char c)
{
	while (str[index] != '\0' && str[index] != c)
		index++;
	return (str[index] == c ? index  : (size_t)NULL);
}

int get_next_line(const int fd, char **line)
{
	char buf[BUF_SIZE + 1];
	int ret;
	static t_line all;
	*line = NULL;
	if (all.ligne == NULL)
		all.ligne = ft_strnew(BUF_SIZE + 1);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		all.ligne = ft_strjoin(all.ligne, buf);
		all.len = ft_strlen(all.ligne);
	}
	while (all.ligne[all.index] == '\n' && all.ligne[all.index])
		all.index++;
	*line = ft_strsub(all.ligne, all.index, ft_strlchr(all.ligne, all.index, '\n'));
	all.index = all.index + ft_strlchr(all.ligne, all.index, '\n');
	printf(" INDEX %zu LEN %zu\n", all.index, all.len - 1);
	return (all.index == all.len - 1 ? 0 : 1);
}