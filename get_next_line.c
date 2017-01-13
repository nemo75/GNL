/* ************************************************************************** */
/*                                                                            */
/*                       6666554123555                                 :::    */
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

static char *ft_strlchr(char *str, char c)
{
	int index = 0;
	char *tmp;
	tmp = (char *)malloc(sizeof(str + 1));
	while (str[index] != '\0' && str[index] != c)
	{
		tmp[index] = str[index];
		index++;
	}
	return (str[index] == c ? tmp  : NULL);
}




char	*ft_strpchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	while (*s == c)
		s++;
	return (*s  != c ? (char *)s : NULL);
}



int get_next_line(const int fd, char **line)
{
	int ret;
	char *ligne = NULL;
	char *test = NULL;
	char *tmp = NULL;
	static t_line all;
	*line = NULL;
	if (ligne == NULL || test == NULL || all.reste == NULL || tmp == NULL)
	{
		if(all.reste == NULL)
		{
			// printf("%s\n", "reste");
			all.reste = ft_strnew(BUF_SIZE );
		}
		if(ligne == NULL)
		{
			// printf("%s\n","ligne" );
			ligne = ft_strnew(BUF_SIZE);
		}
		if(test == NULL)
		{
			// printf("%s\n", "test");
			test = ft_strnew(BUF_SIZE);
		}
		if(tmp == NULL)
		{
			 // printf("%s\n", "tmp");
			tmp = ft_strnew(BUF_SIZE );
		}
	}
	if (all.reste[0] == '\0')
	{
		while ((ret = read(fd, ligne, BUF_SIZE)))
		{
			if ((ft_strchr(ligne, '\n')) != NULL)
			{
				all.tmp = ligne;
				test =  ft_strlchr(ligne, '\n');
				all.reste = ft_strpchr(ligne, '\n');
				tmp = ft_strjoin(tmp, test);
				*line = tmp;
				// free(ligne);
				// free(tmp);
				// free(test);
				return TRUE;
			}
			else
			{
				tmp = ft_strjoin(tmp, ligne);
				printf("%s\n",tmp );
			}
		}
	}
	else
	{
			tmp = ft_strjoin(all.reste, all.tmp);
			free(all.reste);
	}
	*line = tmp;
	return (1);
}






















































	// while (ligne[b] != '\n' && ligne[b] != '\0')
	// {
	// 	all.tmp[all.index++] = ligne[b++];
	// }


	//  printf("%s\n", all.tmp);



	// if (ligne[b] == '\n')
	// {
	// 	b++;
	// 	while (ligne[b] != '\n' && ligne[b] != '\0')
	// 	{
	// 		all.reste[i++] = ligne[b++];
	// 	}
	// 	if (all.reste[0] == '\0')
	// 	{
	// 		//*line = all.tmp;
	// 		ft_strdel(&all.tmp);
	// 		ft_strdel(&all.reste);
	// 	}
	// 	else
	// 	{
	// 		//ft_strdel(&all.tmp);
	// 		// *line = all.tmp;
	// 		// printf("%s",all.reste);
	// 		ft_strdel(&all.tmp);
	// 		ft_strdel(&all.reste);
	// 	}
	// }





// if (all.reste[0] != '\0')
// 	{
// 		*line = all.reste;
// 		i = ft_strlchr(all.reste, 0, '\n') + 1;
// 	}
// 	else
// 	{
// 			*line = ft_strsub(ligne, 0, ft_strlchr(ligne, 0 , '\n'));
// 			i = ft_strlchr(ligne, 0, '\n') + 1;
// 	}
// 	while(ligne[i] != '\n' && ligne[i] != '\0')
// 			all.reste[b++] = ligne[i++];





// if (all.reste[0] != '\0')
// 	{
// 		*line = all.reste;
// 		while(ligne[all.index] != '\n' && ligne[all.index] != '\0')
// 		{
// 			*line = &ligne[all.index++];
// 		}
// 	}
// 	else
// 	{
// 		*line = ft_strsub(ligne, b, ft_strlchr(ligne, b, '\n'));
// 	}

// 	while(ligne[b] != '\n' && ligne[b] != '\0')
// 		all.reste[i++] = ligne[b++];
// 	printf("%s\n",all.reste );

// 	//all.index = all.index + ft_strlchr(all.ligne, all.index, '\n');
// 	return 1;
