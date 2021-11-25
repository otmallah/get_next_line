


// char *get_next_line(int fd)
// {
//     char    *buff;
//     static char *str;
//     char    *temp;
//     int i;
//     int j;

//     if (fd < 0)
//         return NULL;
//     buff = (char *)malloc(sizeof(char) * BUFFER_SIZE);
//     buff[BUFFER_SIZE + 1] = '\0';
//     if (j < 0)
//         return NULL;
//     str = ft_strdup(buff);
//     while(str[i])
//     {
//         if (ft_strchr(str, '\n') != NULL)
//         {
//             temp = ft_substr(str, 0, i);
//             return temp;
//         }
//         else if (ft_strchr(str, '\n') == NULL)
//         {
//             str = ft_strjoin(str, buff);
//             j = read(fd, buff, BUFFER_SIZE);
//             if (j <= 0)
//                 return NULL;
//             i = -1;
//         }
//         i++;
//     }
    
// }