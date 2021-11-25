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
	return (str1);
}

char	*ft_strjoin_sec( char *s1,  char *s2)
{
	char	*str;
	int		k;
	int		i;
	int		j;

	while (s1[i])
		i++;
	while (s2[j] != '\n')
		j++;
	str = (char *)calloc(1, (i + j));
	if (!str)
		return (NULL);
	ft_strcat(str, s1);
	ft_strcat_2(str, s2);
	return (str);
}


char    *get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	//static char	*str;
	static char *temp;
	static int 	a;
	int k;
	static int 	i;
	static int 	j;

	i = 0;
	a = 0;
	buff[BUFFER_SIZE + 1] = '\0';
	temp = ft_strdup("");
 	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	if (buff)
	{
		k = ft_strchr_frr(buff, '\n');
		if (k != 0)
			temp = ft_strjoin(temp, &buff[k + 1]);
	}
	// else
	// {
	// 	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	// 	if (!buff)
	// 		return NULL;
	// }
	//temp = ft_strdup(buff);
	while (1)
	{
		read(fd, buff, BUFFER_SIZE);
		if (ft_strchr(buff, '\n') != 0)
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

	fd = open("fff", O_CREAT | O_RDWR , 0777);
	//get_next_line(fd);
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
	printf("%s\n" , get_next_line(fd));
}


// char	*gnl(int fd)
// {
// 	int ret;
// 	static char *buf
// 	char *temp = "";

// 	if (buf)
// 	{	
// 		if (ft_strchr_frr(buf, '\n') == 5)
// 		{
// 			temp = add_buf_mn_\n()
// 			return (temp)
// 		}
// 	}
// 	else
// 		buf alocate
// 	while (1)
// 	{		
// 		read(fd, buf, BUFFER_SIZE);
// 		if (ft_strchr_frr(buf, '\n') == 5)
// 		{
// 			temp = add_buf_htal_\n()
// 			return (temp)
// 		}
// 		else
// 			temp = join(buf)
// 	}
