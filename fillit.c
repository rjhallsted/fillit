/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:55:18 by sjuery            #+#    #+#             */
/*   Updated: 2017/10/01 13:16:10 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char const *argv[]) {
    char *tetriminos;
    if(argc == 2)
    {
        tetriminos = read_input(argv[1]);
        if(!check_input(tetriminos))
            crash_report("Input File Crashes\n");
        // printf("%s", tetriminos);
    }
    return 0;
}
