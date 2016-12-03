/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skynet <skynet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 02:36:47 by thbricqu          #+#    #+#             */
/*   Updated: 2016/12/03 07:30:37 by skynet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	char 	*line;
	int		fd;

	line = NULL;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr("cant open file : ");
			ft_putendl(argv[1]);
			return (0);
		}
		while (get_next_line(fd, &line) == 1)
		{
			//ft_putendl(line);
			if (line)
				free(line);
		}
		close(fd);
	}
	return (0);
}
