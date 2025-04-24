/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:55:02 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/15 09:55:02 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_alnum(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(char const *str);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, void const *src, size_t n);
void				*ft_memmove(void *dest, void const *src, size_t n);
size_t				ft_strlcpy(char *dest, char const *src, size_t size);
size_t				ft_strlcat(char *dest, char const *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
char				*ft_strnstr(char const *str, char const *to_find,
						size_t len);
int					ft_atoi(char const *nptr);

char				*ft_strdup(char const *s);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s, char const *set);
char				**ft_split(char const *s, char const *set);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *newlink);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *newlink);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

int					ft_min(int a, int b);
size_t				ft_min_size(size_t a, size_t b);
long				ft_min_l(long a, long b);
int					ft_max(int a, int b);
size_t				ft_max_size(size_t a, size_t b);
long				ft_max_l(long a, long b);
long				ft_abs_l(long nb);
int					ft_abs(int nb);

int					ft_any(int *tab, int len, int (*f)(int));
int					ft_strany(char *str, int (*f)(char));
int					*ft_find(int *tab, int len, int x);
void				ft_striter(char *s, void (*f)(char *));
void				ft_sort_int_tab(int *tab, int size);
void				ft_swap(int *a, int *b);
char				**free_split(char **words);
int					ft_countwords(char const *s, char const *set);
int					ft_wordlen(char const *s, char const *set);
int					ft_posinset(char c, char const *set);

int					ft_printf(const char *fmt, ...);
int					ft_dprintf(int fd, const char *fmt, ...);
int					ft_vdprintf(int fd, const char *fmt, va_list *ap);

char				*get_next_line(int fd);

#endif
