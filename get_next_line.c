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

char	*ft_strpchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		s++;
	return ((char *)s);
}

char *ft_realloc(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str == NULL)
		return (NULL);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	free(s1);
	return (str);
}

int		gnl_split(t_line *all, char **line)
{
	char *str;
	str = ft_strdup(ft_strpchr(all->ligne, '\n'));
	*line = ft_strsub(all->ligne, 0, (ft_strchr(all->ligne, '\n') - &all->ligne[0]));
	free(all->ligne);
	all->ligne = str;
	return TRUE;
}

int	 get_next_line(const int fd, char **line)
{
	static t_line *all;
	if (all == NULL )
	{
		all = (t_line*)malloc(sizeof(t_line));
		all->ligne = ft_strnew(BUF_SIZE);
	}
	if (fd < 0)
		return (FALSE);
	if (ft_strchr(all->ligne, '\n') != NULL && all->ligne != NULL)
		return (gnl_split(all, line));
	else 
	{
		while ((all->ret = read(fd, all->tmp, BUF_SIZE)))
		{
			all->tmp[all->ret] = '\0';
			all->ligne = ft_realloc(all->ligne, all->tmp);
			if (all->ret == -1)
				return (FALSE);
			if (ft_strchr(all->ligne, '\n') != NULL)
				return (gnl_split(all, line));
		}
	}
		if (all->c == 0)
		{
			*line = all->ligne;
			all->c = 1;
			return TRUE;
		}
	return FALSE;
}













































// if (ligne == NULL || test == NULL || all.reste == NULL || tmp == NULL)
// 	{
// 		if(all.reste == NULL)
// 		{
// 			// printf("%s\n", "reste");
// 			all.reste = ft_strnew(BUF_SIZE );
// 		}
// 		if(ligne == NULL)
// 		{
// 			// printf("%s\n","ligne" );
// 			ligne = ft_strnew(BUF_SIZE);
// 		}
// 		if(test == NULL)
// 		{
// 			// printf("%s\n", "test");
// 			test = ft_strnew(BUF_SIZE);
// 		}
// 		if(tmp == NULL)
// 		{
// 			 // printf("%s\n", "tmp");
// 			tmp = ft_strnew(BUF_SIZE );
// 		}
// 	}

// 		while ((ret = read(fd, ligne, BUF_SIZE)))
// 		{
// 			printf("%s\n",all.reste );
// 			if (all.reste[0] != '\0')
// 				{
// 					printf("%s\n","coucou" );
// 					tmp = ft_strjoin(all.reste, ligne);
// 					free(all.reste);
// 				}
// 			else if ((ft_strchr(ligne, '\n')) != NULL)
// 			{
// 				all.tmp = ligne;
// 				test =  ft_strlchr(ligne, '\n');
// 				all.reste = ft_strpchr(ligne, '\n');
// 				tmp = ft_strjoin(tmp, test);
// 				*line = tmp;
// 				 free(ligne);
// 				 //free(tmp);
// 				// free(test);
// 				return TRUE;
// 			}
// 			else
// 			{
// 				tmp = ft_strjoin(tmp, ligne);
// 			}
// 		}

// 	*line = tmp;








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
