/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:23:43 by jimin             #+#    #+#             */
/*   Updated: 2022/11/11 13:24:12 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scene.h"

t_canvas	set_canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}
