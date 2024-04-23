/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 15:42:38 by agan              #+#    #+#             */
/*   Updated: 2024/04/10 15:42:40 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		game.mlx_ptr = mlx_init();
		init_map(&game, argv[1]);
		init_colors(&game.map);
		init_textures(&game, &game.map);
		init_window(&game);
	}
}
