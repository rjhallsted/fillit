/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:31:58 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/05 12:01:53 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "fillit.h"

# define MIN(a, b) ((a > b) ? b : a)
# define MAX(a, b) ((a > b) ? a : b)

void				ft_bzero(void *s, size_t n);
void				ft_free_2d_array(void ***array, size_t size);
void				*ft_memalloc(size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strcpy(char *dst, char const *src);
char				*ft_strdup(const char *s1);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				**ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, char const *src, size_t n);
char				*ft_strnew(size_t size);
size_t				ft_strlen(char const *s);
void				ft_swap(int *a, int *b);

#endif
