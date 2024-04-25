/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliew <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:05:26 by yliew             #+#    #+#             */
/*   Updated: 2024/04/10 16:05:28 by yliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_to_window(t_game *game, t_img *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		image->ptr, x, y);
}

void	get_texture_info(t_img *texture)
{
	texture->addr = mlx_get_data_addr(texture->ptr, &texture->bpp,
			&texture->line_size, &texture->endian);
}

void	new_texture(t_game *game, t_img *texture, char *path)
{
	texture->ptr = mlx_xpm_file_to_image(game->mlx_ptr, path,
			&texture->x, &texture->y);
	get_texture_info(texture);
}

char	*get_pixel_pos(t_img *image, int x, int y)
{
	return (image->addr + (y * image->line_size + x * (image->bpp / 8)));
}

void	ft_put_pixel(t_img *image, int x, int y, unsigned int colour)
{
	char	*pos;

	pos = get_pixel_pos(image, x, y);
	*(unsigned int *)pos = colour;
}