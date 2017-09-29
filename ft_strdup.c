/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 19:09:13 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/28 16:16:25 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strdup(const char *str)
{
	char	*nstr;

	nstr = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!nstr)
		return (NULL);
	else
		return (ft_strcpy(nstr, str));
}
