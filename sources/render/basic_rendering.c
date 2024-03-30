/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Axel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:43:53 by Axel              #+#    #+#             */
/*   Updated: 2024/03/30 15:46:35 by Axel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	render_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bbp / 8));
	*(unsigned int *)dst = color;
}

void	render_square(t_img *img, t_square square)
{
	int	i;
	int	j;

	i = square.y;
	if ((square.x + square.width > SCREEN_W || square.x < 0) && (square.y
			+ square.width > SCREEN_H || square.y < 0))
		return ;
	while (i < square.y + square.width)
	{
		j = square.x;
		while (j < square.x + square.width)
			render_pixel(img, j++, i, square.color);
		i++;
	}
}

void	render_line(t_point start, t_point dir, int length, int color)
{
	int	i;

	i = -1;
	while (++i < length)
	{
		render_pixel(&game()->screen_buff, start.x + dir.x, start.y + dir.y,
			color);
		start.x += dir.x;
		start.y += dir.y;
	}
}
