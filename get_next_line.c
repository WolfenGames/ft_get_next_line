/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:40:18 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 19:47:10 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

char            *strchar(char const *s1, char c)
{
    char    *new;
    size_t  i;
    size_t  j;

    if (!s1 || !c)
        return (NULL);
    j = ft_strlen(s1);
    new = ft_strnew(j + 1);
    if (!new)
        return (NULL);
    i = -1;
    while (++i < j)
        *(new + i) = *(s1 + i);
    *(new + i) = c;
    return (new);
}

static int      copychar(char **dst, char *src, char c)
{
    int     i;
    int     count;
    int     pos;

    i = -1;
    count = 0;
    while (src[++i])
        CON_BREAK((src[i] == c));
    pos = i;
    if (!(*dst = ft_strnew(i)))
        return (0);
    while (src[count] && count < i)
    {
        if (!(*dst = strchar(*dst, src[count])))
            return (0);
        count++;
    }
    return (pos);
}

int             get_next_line(int const fd, char **line)
{
    static char     *mem;
    char            buf[BUFF_SIZE + 1];
    int             ret;
    int             i;

    if (!line || fd < 0 || BUFF_SIZE < 0)
        return (-1);
    MALLCHECK_I((mem = ft_memalloc(sizeof(*mem))));
    while ((ret = read(fd, buf, BUFF_SIZE)))
    {
        buf[ret] = '\0';
        MALLCHECK_I((mem = ft_strjoin(mem, buf)));
        CON_BREAK(ft_strrchr(buf, '\n'));
    }
    if (ret < BUFF_SIZE && !ft_strlen(mem))
        return (0);
    i = copychar(line, mem, '\n');
    (i < (int)ft_strlen(mem)) ? mem += (i + 1) : ft_strclr(mem);
    return (1);
}
