#include "get_next_line.h"

size_t ft_strlen(const char *str);

static char	*ft_strcat(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i])
	{
		i++;
	}
	while (str2[j])
	{
		str1[i + j] = str2[j];
		j++;
	}
	str1[i + j] = '\0';
	return (str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		k;
	int		i;
	int		j;

	k = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	str = (char *)malloc(i + j + 2);
	if (!str)
		return (NULL);
	str[0] = '\0';
	if (!str)
		return (NULL);
	ft_strcat(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	return (str);
}


static void	check(const char *s, char *su, int sta, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= sta && j < len)
		{
			su[j] = s[i];
			j++;
		}
		i++;
	}
	su[j] = '\0';
}

size_t ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return i;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	a;
	char	*sub;

	i = 0;
	j = 0;
	a = len + 1;
	if (s == NULL)
		return (NULL);
	if (a > ft_strlen(s))
		a = ft_strlen((s) + 1);
	sub = (char *)malloc(sizeof(char) * a);
	if (!sub)
		return (NULL);
	check(s, sub, start, len);
	return (sub);
}


int	ft_strchr_frr(const char *str, int c)
{
	int		i;
	char	*st;

	st = (char *)str;
	i = 0;
	while (st[i])
	{
		if (st[i] == (char)c)
			return i;
		i++;
	}
    return 0;
}

int	ft_strchr(const char *str, int c)
{
	int		i;
	char	*st;

	st = (char *)str;
	i = 0;
	while (st[i])
	{
		if (st[i] == (char)c)
			return (5);
		i++;
	}
	return (0);
}


char	*ft_strdup(const char *str)
{
	char	*se;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	se = (char *)malloc((i + 1) * sizeof(char));
	if (!se)
		return (NULL);
	while (str[j])
	{
		se[j] = str[j];
		j++;
	}
	se[j] = '\0';
	return (se);
}
