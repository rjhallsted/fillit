/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:01:30 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/02 15:58:15 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char const *argv[]) {
    char *tetriminos;
    char **split_tetriminos;
    if(argc == 2)
    {
        tetriminos = read_input(argv[1]);
        if(!check_input(tetriminos))
			return (1);
        split_tetriminos = tetri_split(tetriminos);
    }
    return 0;
}
