/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eddos-sa <eddos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:26:11 by eddos-sa          #+#    #+#             */
/*   Updated: 2024/04/18 12:23:50 by eddos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "utils/utils_lib.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Get Next Line
char				*get_next_line(int fd);

// Printf fd
int					ft_printf_fd(int fd, const char *format, ...);

// Handle String Functions
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

int					ft_array_len(char **array);
int					ft_strcmp(char *s1, char *s2);
int					ft_strcmp_len(char *s1, char *s2);
int					ft_strncmp(const char *str1, const char *str2, size_t n);

size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strdup(const char *str);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin_char(char *s, char c);
char				*ft_strrchr(const char *s, int c);
char				**ft_split(char const *string, char chr);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, const char *set);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_substr(const char *s, unsigned int start, size_t len);

// Handle Char Functions
int					ft_toupper(int c);
int					meta_char(char c);
int					ft_tolower(int c);
int					ft_isspace(char c);
int					ft_isspace(char c);
int					ft_isalnum(int digit);
int					ft_isascii(int ascii);
int					ft_isprint(int print);
int					ft_isdigit(int number);
int					ft_isalpha(int letter);
int					ft_isalldigit(const char *str);
int					count_equals_chr(char *str, char c);

// Handle Standard Functions
void				close_fd(void);
void				ft_putstring_fd(int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);

// Handle Memory Functions
void				free_array(char **array);
void				ft_bzero(void *s, size_t n);
void				shift_args(char **args, int start);
void				*ft_calloc(size_t nitems, size_t size);
void				*ft_memset(void *s, int bytes, size_t memory);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				*ft_memchr(const void *ptr, int value, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);

int					ft_memcmp(const void *ptr1, const void *ptr2, size_t n);

// Handle Math Functions
char				*ft_itoa(int n);

int					ft_atoi(const char *str);

long double			ft_atof(char *str);

long int			ft_atol(const char *str);

// Handle List Functions
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(void *));
void				ft_lstadd_front(t_list **lst, t_list *new);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(void *content);

// Handle Files Functions
int					file_exist(char *file_name);
int					file_is_readable(char *file_name);
int					file_is_writable(char *file_name);
int					file_is_executable(char *file_name);

#endif