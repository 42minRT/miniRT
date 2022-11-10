/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_basic_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:11:46 by jaekim            #+#    #+#             */
/*   Updated: 2022/11/10 16:11:47 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/color.h"

t_color3	red(void)
{
	return (set_color_rgb(255, 0, 0));
}

t_color3	green(void)
{
	return (set_color_rgb(0, 255, 0));
}

t_color3	blue(void)
{
	return (set_color_rgb(0, 0, 255));
}

t_color3	white(void)
{
	return (set_color_rgb(255, 255, 255));
}

t_color3	black(void)
{
	return (set_color_rgb(0, 0, 0));
}
