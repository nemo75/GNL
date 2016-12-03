/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbricqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 02:18:39 by thbricqu          #+#    #+#             */
/*   Updated: 2016/12/03 02:18:41 by thbricqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int get_next_line(const int fd, char **line)
{
	size_t i;
	char buf[BUF_SIZE + 1];
	int ret;
	char *tmp;
	static t_line current_line = NULL;
	
	i = 0;
	if ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		printf("%s\n", "passage");
		*line = ft_strjoin(ft_strdup(current_line.all), buf);
	}
	else
		return (FALSE);
	return (TRUE);
}