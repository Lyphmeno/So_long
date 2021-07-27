/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:36:58 by hlevi             #+#    #+#             */
/*   Updated: 2021/07/27 13:07:02 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# define LOWHEXA "0123456789abcdef"
# define UPHEXA "0123456789ABCDEF"

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t len);
void			*ft_calloc(size_t count, size_t size);
char			*ft_chartostring(int c);
int				ft_hexalen(unsigned long nb);
int				is_not_char(char *str, char c);
int				is_charset(char c, char *charset);
char			*ft_itoa(int n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			**ft_newarray(size_t w, size_t h, size_t size);
void			ft_strcat(char *dst, char *src);
char			*ft_strchr(const char *s, int c);
int				ft_strcmp(char *s1, char *s2);
void			ft_strcpy(char *dst, char *src);
char			*ft_strdup(char *src);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strndup(char *src, size_t n);

#endif
