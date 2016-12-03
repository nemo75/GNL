/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skynet <skynet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 02:18:39 by thbricqu          #+#    #+#             */
/*   Updated: 2016/12/03 07:29:05 by skynet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

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
		buf[ret] = '\0';
		all.ligne = ft_strjoin(all.ligne, buf);
	}
	while (all.ligne[all.index])
	{
		ft_putchar(all.ligne[all.index++]) ;
		if (all.ligne[all.index] == '\n')
			ft_putchar('\n');
		while (all.ligne[all.index] == '\n')
			all.index++;
	}
	free(all.ligne);
	if (!(ret = read(fd, buf, BUF_SIZE)))
		return FALSE;
	return (TRUE);
}