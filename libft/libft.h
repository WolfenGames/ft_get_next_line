/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:44:03 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/28 16:32:16 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define MIN_INT        -2147483648
# define MAX_INT        2147483647
# define SUCCESS		0
# define ERROR			1
# define TRUE           1
# define FALSE          0
# define MALLCHECK(x)   if (!x) return (-1)
# define EVEN(x)		(!(x % 2))
# define IS_SPACE(x)    (x == ' ' || x == '\t' || x == '\r' || x == '\f')
# define ABS(x)			((x < 0) ? x : -x)

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef	char			*t_str;
typedef unsigned char	t_uchar;
typedef unsigned char	*t_ustr;
typedef const char		*t_cstr;
typedef void			*t_void;
typedef void			**t_lstvoid;
typedef const void		*t_cvoid;
typedef	char			**t_lststr;
typedef	int				t_bool;
typedef unsigned int	t_uint;
typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

void					ft_bzero(t_void s, size_t n);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void(*del)(t_void, size_t));
void					ft_lstdelone(t_list **alst, void(*del)(t_void, size_t));
void					ft_lstiter(t_list *lst, void(*f)(t_list *elem));
void					ft_memdel(t_lstvoid ap);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(t_cstr s);
void					ft_putendl_fd(t_cstr s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr(t_str str);
void					ft_putstr_fd(t_cstr s, int fd);
void					ft_strclr(t_str as);
void					ft_strdel(t_lststr as);
void					ft_striter(t_str s, void (*f)(t_str));
void					ft_striteri(t_str s, void (*f)(t_uint, t_str));

t_void					ft_memalloc(size_t size);
t_void					ft_memcpy(t_void str1, t_cvoid str2, size_t n);
t_void					ft_memccpy(t_void str1, t_cvoid str2, int c, size_t n);
t_void					ft_memchr(t_cvoid str, int c, size_t n);
t_void					ft_memmove(t_void str1, t_cvoid str2, size_t n);
t_void					ft_memset(t_void str, int c, size_t n);

int						ft_atoi(t_cstr str);
int						ft_clearspace(t_cstr s, int c);
int						ft_memcmp(t_cvoid str1, t_cvoid str2, size_t n);
int						ft_strcmp(t_cstr s1, t_cstr s2);
int						ft_strequ(t_cstr s1, t_cstr s2);
int						ft_strncmp(t_cstr s1, t_cstr s2, size_t n);
int						ft_strnequ(t_cstr s1, t_cstr s2, size_t n);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_wordcount(t_cstr s, char c);

size_t					ft_strlcat(t_str dest, t_cstr src, size_t size);
size_t					ft_strlen(t_str s1);

t_bool					ft_isascii(int c);
t_bool					ft_isalnum(int c);
t_bool					ft_isalpha(int c);
t_bool					ft_intminmax(int c);
t_bool					ft_isdigit(int c);
t_bool					ft_isprint(int c);

t_str					ft_strcat(t_str dest, t_cstr src);
t_str					ft_strchr(t_cstr str, int c);
t_str					ft_strcpy(t_str dest, t_cstr src);
t_str					ft_strdup(t_cstr s1);
t_str					ft_strsub(t_cstr s, t_uint start, size_t end);
t_str					ft_itoa(int n);
t_str					ft_strjoin(t_cstr s1, t_cstr s2);
t_str					ft_strmap(t_cstr s, char (*f)(char));
t_str					ft_strmapi(t_cstr s, char (*f)(t_uint, char));
t_str					ft_strncat(t_str dest, t_cstr src, size_t n);
t_str					ft_strncpy(t_str dest, t_cstr src, size_t n);
t_str					ft_strnew(size_t size);
t_str					ft_strnstr(t_cstr hay, t_cstr needle, size_t n);
t_str					ft_strrchr(t_cstr str, int c);
t_str					ft_strstr(t_cstr hay, t_cstr needle);
t_str					ft_strsub(t_cstr s1, t_uint start, size_t len);
t_str					ft_strtrim(t_cstr s);
t_str					ft_strtrimcpy(t_str ret, t_cstr s, int start, int end);

t_uchar					ft_swap_bits(t_uchar octet);

t_lststr				ft_strsplit(t_cstr s, char c);

t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(t_cvoid content, size_t content_size);

#endif
