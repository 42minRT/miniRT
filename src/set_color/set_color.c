/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:11:59 by jaekim            #+#    #+#             */
/*   Updated: 2022/11/10 16:12:00 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/color.h"

t_color3	set_color_rgb(double r, double g, double b)
{
	t_color3	color;

	color.x = r;
	color.y = g;
	color.z = b;
	return (color);
}
