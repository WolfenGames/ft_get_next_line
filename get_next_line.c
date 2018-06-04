/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:10:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 12:01:52 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

static char		*strcat_c(char *s1, char c)
{
	char	*new;
	size_t	i;

	STRCHECK((s1 || c));

	MALLCHECK_N((new = ft_strnew(ft_strlen(s1) + 1)));
	i = -1;
	while (++i < ft_strlen(s1))
		*(new + i) = *(s1 + i);
	*(new + i) = c;
	return (new);
}

static	int		contentcopy(char **dst, char *src, char c)
{
	int		i;
	int		pos;
	int		cc;

	i = -1;
	cc = 0;
	while (src[++i])
		CON_BREAK(src[i] == c);
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[cc] && cc < i)
	{
		if (!(*dst = strcat_c(*dst, src[cc])))
			return (0);
		cc++;
	}
	return (pos);
}

static t_list	*get_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
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
		buf[ret] = '\0';
		MALLCHECK_I((c_file->content = ft_strjoin(c_file->content, buf)));
		if (ft_strrchr(buf, '\n'))
			break ;
	}
	SUCC_CHECK((ret < BUFF_SIZE && !ft_strlen(c_file->content));
	i = contentcopy(line, c_file->content, '\n');
	(i < (int)ft_strlen(c_file->content)) ? c_file->content += (i + 1) :
		ft_strclr(c_file->content);
	return (1);
} 
