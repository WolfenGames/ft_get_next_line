/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 16:11:10 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/21 06:58:32 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE	   	32
# define FD_MAX			1000	

# include <unistd.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

int		get_next_line(const int fd, char **line);

#endif
