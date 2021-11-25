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
	str1[i + j] = '\0';
	return (str1);
}

char	*ft_strjoin_sec(char *s1, char *s2)
{
	char	*str;
	int		j;

	j = 0;
	while (s2[j] != '\n')
		j++;
	str = (char *)calloc(1, (ft_strlen(s1) + j));
	if (!str)
		return (NULL);
	ft_strcat(str, s1);
	ft_strcat_2(str, s2);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	static char	*temp;
	char		*help;
	static int j;
	int			k;

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
			temp = ft_strjoin_sec(temp, help);
			return (temp);
		}
		else
		{
			temp = ft_strjoin(temp, help);
		}
	}
	else
	{
		buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
	}
	// printf("Temp: %s\n",temp);
	while (j >= 0)
	{
		j = read(fd, buff, BUFFER_SIZE);
		buff[j + 1] = '\0';
		if (j == 0)
		{
			if (strncmp(temp,"\0",1) == 0)
				return(NULL);
			else
				return (temp);
		}
		if (ft_strchr(buff, '\n') != 0 && j >= 0)
		{
			temp = ft_strjoin_sec(temp, buff);
			return (temp);
		}
		else
			temp = ft_strjoin(temp, buff);
	}
	return temp;
}


int main(void)
{
	int fd;
	int i;

	i = 0;
	fd = open("555", O_RDONLY);
	//get_next_line(fd);
	char *str;
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));

}