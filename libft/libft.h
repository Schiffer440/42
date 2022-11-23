/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:28:55 by adugain           #+#    #+#             */
/*   Updated: 2022/11/08 10:29:02 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H_
#define LIBFT_H_

#include <stdlib.h>
#include <unistd.h>

int	ft_isalpha(char c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
size_t ft_strlen(const char *str);
void *ft_memset(void *s, int c, size_t n);
void ft_bzero(void *s, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t n);
int ft_atoi(char *str);
void *ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int ft_toupper(int c);
int ft_tolower(int c);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void *ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(char *src);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
void	ft_putnbr_fd(int nb, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putchar_fd(char c, int fd);
void    ft_putendl_fd(char *s, int fd);
char    *ft_itoa(int n);
char **ft_split(char const *s, char c);

#endif