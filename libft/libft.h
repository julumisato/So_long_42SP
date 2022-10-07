/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jusato <jusato@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:06:05 by jusato            #+#    #+#             */
/*   Updated: 2022/10/07 04:28:32 by jusato           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_printf
{
	va_list		args;
	int			ret;
	int			fill_zero;
	int			left_posit;
	int			altern_form;
	int			space;
	int			signal;
	int			min;
}	t_printf;

/*_________________________________LIBFT_________________________________*/

/* .............................<ctype.h> functions....*/
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/*.............................<string.h> functions....*/
size_t		ft_strlen(const char *str);
void		*ft_memset(void *str, int c, size_t n);
void		ft_bzero(void *str, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dest, const char *src, size_t n);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
char		*ft_strnstr(const char *str1, const char *str2, size_t n);
int			ft_atoi(const char *str);

/*.............................<stdlib.h> functions...*/
void		*ft_calloc(size_t nelem, size_t elsize);
char		*ft_strdup(const char *src);

/*..............Part 2 functions......................*/
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*.............Bonus functions........................*/
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);

/*_________________________________ GNL _________________________________*/

char		*get_next_line(int fd);

/*_________________________________FT_PRINTF_________________________________*/

/* initial functions (ft_printf.c) */
int			ft_printf(const char *format, ...);
int			ft_eval_format_string(t_printf *param, const char *string);
t_printf	*ft_init(t_printf	*init);
int			ft_flags(t_printf *param, char *flag);

/* format functions (ft_printf_formats.c) */
void		ft_printf_alnum(t_printf *param, char c);
void		ft_printf_string(t_printf *param);
void		ft_printf_pointer(t_printf *param);
void		ft_printf_unsigned_int(t_printf *param);
void		ft_printf_hexadecimal(t_printf *param, char h);

/* utils (ft_printf_utils[1/2].c) */
int			ft_numlen(int num);
int			ft_sizehexa(unsigned long long n);
int			ft_unsigned_numlen(unsigned int n);
void		ft_put_unsignednbr(unsigned int n);
char		*ft_hexastr(unsigned long n, char h);
void		ft_printf_char(t_printf *param, char c);
void		ft_printf_num(t_printf *param, int value);
void		ft_printf_str_width(t_printf *param, char *str);
void		ft_printf_ptr_width(t_printf *param, char *str);

/* new utils so_long */
void	*ft_diff_chrstr(char *str, int c);

#endif
