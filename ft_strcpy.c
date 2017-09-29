/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 14:02:27 by sjuery            #+#    #+#             */
/*   Updated: 2017/09/28 16:04:58 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *ndst;

	ndst = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (ndst);
}
