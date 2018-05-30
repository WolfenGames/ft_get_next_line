/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:11:10 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/30 18:13:11 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE		32	
# define MALLCHECK(x)	if (!x) return (-1)

# include <unistd.h>
# include <fcntl.h>

int		get_next_line(const int fd, char **line);

#endif
