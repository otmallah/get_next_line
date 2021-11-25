#include "get_next_line.h"

char	*gnl(int fd)
{
	int ret;
	static char *buf;
	char *temp;
    int i;
    int j;
    int a;

    a = 0;
	if (buf)
	{	
        i = ft_strchr_frr(buf, '\n');
		if (i != 0)
		{
			temp = ft_substr(buf, a, i);
			return (temp);
		}
	}
	else
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	read(fd, buf, BUFFER_SIZE);
    i = ft_strchr_frr(buf, '\n');
	if (i != 0)
	{
		temp = ft_substr(buf, a, i);
		return (temp);
	}
	else
		temp = ft_strjoin(temp, buf);

}

int main(void)
{
	int fd;
	char *str;

	fd = open("fff", O_CREAT | O_RDWR , 0777);
	//get_next_line(fd);
	printf("%s\n" , gnl(fd));
	printf("%s\n" , gnl(fd));
	printf("%s\n" , gnl(fd));

}