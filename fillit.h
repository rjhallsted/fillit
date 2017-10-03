/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 11:36:45 by rhallste          #+#    #+#             */
/*   Updated: 2017/10/03 14:32:23 by rhallste         ###   ########.fr       */
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

int					loop_through_candidates(char **map, size_t map_size, t_list *piece);
int					consider_candidate(char **map, size_t map_size, t_list *piece, t_coords *coords);
int					accept(t_list *piece);
void				set_piece(char **map, t_list *piece, t_coords *coords);
void				remove_piece(char **map, size_t map_size, t_list *piece);
t_coords			*find_first_placement(char **map, size_t map_size, t_list *piece, size_t start_at);
int					can_place_here(char **map, size_t map_size, t_list *piece, t_coords *coords);

t_list				*new_item(char *shape, char id);
void				free_item(t_list **item);
void				free_list(t_list **item);

char				**make_map(size_t map_size);
void				print_map(char **map, size_t map_size);
void				free_map(char **map, size_t map_size);

char    			*read_input(char const *file);
unsigned int        check_input(char *tetriminos);
t_list				*tetri_split(char const *input);

#endif
