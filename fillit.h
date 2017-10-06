/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:36:45 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/05 17:44:55 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <string.h>

typedef struct		s_coords
{
	int				x;
	int				y;
}					t_coords;

typedef struct		s_list
{
	char			*shape;
	char			id;
	t_coords		*dim;
	struct s_list	*next;
}					t_list;

size_t				g_map_size;

int					loop_candidates(char *map, char **piece, char id);
int					consider(char *map, char **piece, t_coords *coords,
						char id);
int					solution_finder(char **piece);
int					accept(char **piece);
void				set_piece(char *map, char **piece, t_coords *coords,
						char id);
t_coords			*find_placement(char *map, char **piece,
						t_coords *dim, size_t start_at);
void				remove_piece(char *map, char id);
t_coords			*find_dimensions(char const *shape);
int					can_place_here(char *map, char **piece, t_coords *coords,
						t_coords *dim);
char				*make_map(size_t map_size);
void				free_map(char *map, size_t map_size);
char				*read_input(char const *file);
int					validate_input(char *tetriminos);
char				**tetri_split(char const *input);
t_coords			*new_coords(int x, int y);

#endif
