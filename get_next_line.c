/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otmallah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:56:14 by otmallah          #+#    #+#             */
/*   Updated: 2021/11/23 22:56:15 by otmallah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_strcat(char *str1, char *str2)
{
	int	i;
	int	j;

	i = ft_strlen(str1);
	j = 0;
	while (str2[j])
	{
		str1[i + j] = str2[j];
		j++;
	}
	str1[i + j] = '\0';
	return (str1);
}

char	*ft_strcat_2(char *str1, char *str2)
{
	int	i;
	int	j;

	i = ft_strlen(str1);
	j = 0;
	while (str2[j] != '\n')
	{
		str1[i + j] = str2[j];
		j++;
	}
	str1[i + j] = '\n';
	return (str1);
}

char	*ft_strjoin_sec(char *s1, char *s2)
{
	char	*str;
	int		j;

	j = 0;
	while (s2[j] != '\n')
		j++;
	str = (char *)calloc(1, (ft_strlen(s1) + j) + 1);
	if (!str)
		return (NULL);
	ft_strcat(str, s1);
	ft_strcat_2(str, s2);
	return (str);
}

// char	*check_line(char *buff_read, char *temp)
// {
// 	char	*help;
// 	int		k;
// 	char	*first_str;
// 	char	*sec_str;

// 	k = ft_strchr_frr(buff_read, '\n');
// 	buff_read[k] = 'a';
// 	help = &buff_read[k + 1];
// 	if (ft_strchr(help, '\n') != 0)
// 	{
// 		first_str = ft_strjoin_sec(temp, help);
// 		free(temp);
// 		temp = first_str;
// 		return (temp);
// 	}
// 	else
// 	{
// 		sec_str = ft_strjoin(temp, help);
// 		free(temp);
// 		temp = sec_str;
// 		free(buff_read);
// 		buff_read = (char *)calloc(sizeof(char) ,  (BUFFER_SIZE + 1));
// 		buff_read[BUFFER_SIZE] = '\0';
// 		if (!buff_read)
// 			return (NULL);
// 	}
// }

char	*get_next_line(int fd)
{
	static char	*buff;
	static char	*temp;
	char		*help;
	char 		*str;
	char		*set;
	char		*sun;
	char		*see;
	char		*spopo;
	int 		j;
	int			k;

	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = ft_strdup("");
	if (buff)
	{
		k = ft_strchr_frr(buff, '\n');
		buff[k] = 'a';
		help = &buff[k + 1];
		if (ft_strchr(help, '\n') != 0)
		{
			str = ft_strjoin_sec(temp, help);
			free(temp);
			temp = str;
			return (temp);
		}
		else
		{
			set = ft_strjoin(temp, help);
			free(temp);
			temp = set;
			free(buff);
			buff = (char *)calloc(sizeof(char) ,  (BUFFER_SIZE + 1));
			buff[BUFFER_SIZE] = '\0';
			if (!buff)
				return (NULL);
		}
	}
	else
	{
		buff = (char *)calloc(sizeof(char) ,  (BUFFER_SIZE + 1));
		buff[BUFFER_SIZE] = '\0';
		if (!buff)
			return (NULL);
	}
	while (1)
	{
		j = read(fd, buff, BUFFER_SIZE);
		if (j == -1)
		{
			free(buff);
			free(temp);
			buff = NULL;
			return NULL;
		}
		if (j == 0)
		{
			if (strncmp(temp,"\0",1) == 0)
			{
				free(temp);
				return(NULL);
			}
			else
			{
				sun = ft_strjoin(temp, buff);
				free(temp);
				temp = sun;
				return (temp);
			}
		}
		if (ft_strchr(buff, '\n') != 0 && j >= 0)
		{
			see = ft_strjoin_sec(temp, buff);
			free(temp);
			temp = see;
			return (temp);
		}
		else
		{
			spopo = ft_strjoin(temp, buff);
			free(temp);
			temp = spopo;
			buff = (char *)calloc(sizeof(char) ,  (BUFFER_SIZE + 1));
			buff[BUFFER_SIZE + 1] = '\0';
			if (!buff)
				return (NULL);
		}
	}
	return NULL;
}


// int main(void)
// {
// 	int fd;

// 	char *line;
// 	fd = open("file", O_RDONLY);
// 	while ((line = get_next_line(fd))!= NULL)
// 	{
// 		printf("%s" , line);
// 		free(line);
// 	}
// 	//printf("%s\n" , get_next_line(fd));
// 	// printf("%s\n" , get_next_line(fd));
// 	// printf("%s\n" , get_next_line(fd));
// 	// printf("%s\n" , get_next_line(fd));
// 	// printf("%s\n" , get_next_line(fd));
// 	// printf("%s\n" , get_next_line(fd));
// 	// printf("%s\n" , get_next_line(fd));
// 	// printf("%s\n" , get_next_line(fd));
// 	// printf("%s\n" , get_next_line(fd));
// 	// printf("%s\n" , get_next_line(fd));
// 	// printf("%s\n" , get_next_line(fd));
// 	//system("leaks a.out");
// }