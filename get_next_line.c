/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2018/05/28 16:10:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/05 13:12:10 by jwolf            ###   ########.fr       */
=======
/*   Created: 2018/06/04 16:40:18 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 19:47:10 by jwolf            ###   ########.fr       */
>>>>>>> 682e1876475e25ee4725d05ea890e415befd3572
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

<<<<<<< HEAD
static char		*joinnewline(char *s, char c)
=======
char            *strchar(char const *s1, char c)
>>>>>>> 682e1876475e25ee4725d05ea890e415befd3572
{
    char    *new;
    size_t  i;
    size_t  j;

<<<<<<< HEAD
	if (!s || !c)
		return (NULL);
	MALLCHECK_N((new = ft_strnew(ft_strlen(s) + 1)));
	i = 0;
	while (i < ft_strlen(s))
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	return (new);
}

static int		copytillnl(char **dst, char *src, char c)
{
	int		index;
	int		position;
	int		count;
	char	*temp;

	index = -1;
	count = 0;
	while (src[++index])
		CON_BREAK((src[index] == c));
	position = index;
	while (src[count] && count < index)
	{
		temp = *dst;
		if (!(*dst = joinnewline(*dst, src[count])))
			return (0);
		count++;
		free(temp);
	}
	return (position);
=======
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
>>>>>>> 682e1876475e25ee4725d05ea890e415befd3572
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
<<<<<<< HEAD

int				get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp_str;
	int				ret;
	int				i;
	static t_list	*files;
	t_list			*c_file;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	c_file = get_file(&files, fd);
	MALLCHECK_I((*line = ft_strnew(1)));
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		tmp_str = c_file->content;
		buf[ret] = '\0';
		MALLCHECK_I((c_file->content = ft_strjoin(c_file->content, buf)));
		if (tmp_str != NULL)
			free(tmp_str);
		CON_BREAK(ft_strrchr(buf, '\n'));
	}
	SUCC_CHECK((ret < BUFF_SIZE && !ft_strlen(c_file->content)));
	i = copytillnl(line, c_file->content, '\n');
	(i < (int)ft_strlen(c_file->content)) ? c_file->content += (i + 1) :
		ft_strclr(c_file->content);
	return (1);
}
=======
>>>>>>> 682e1876475e25ee4725d05ea890e415befd3572
