/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:10:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/05 13:12:10 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/includes/libft.h"

static char		*joinnewline(char *s, char c)
{
	char	*new;
	size_t	i;

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
