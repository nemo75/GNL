/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbricqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 02:23:53 by thbricqu          #+#    #+#             */
/*   Updated: 2016/12/03 02:23:55 by thbricqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define TRUE 1
# define FALSE 0
# define BUF_SIZE 32

typedef struct				s_line
{
	char	*all;

}							t_line;


int			get_next_line(const int fd, char **line);

#endif