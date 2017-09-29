/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:36:45 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/28 16:16:55 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
 #include <fcntl.h>
 #include <stdlib.h>
 #include <stdio.h>

typedef struct		s_list
{
	char			**shape;
	char			id;
	int				dimensions[2];
	struct s_list	*next;
}					t_list;

char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char    			*read_input(const char *file);

size_t				ft_strlen(const char *str);


#endif
