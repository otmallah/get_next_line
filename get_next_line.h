#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char    *ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int     ft_strchr_frr(const char *str, int c);
char    *ft_strdup(const char *str);
int     ft_strchr(const char *str, int c);
size_t	ft_strlen(char const *str);