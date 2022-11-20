/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_basic_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:53:22 by seongyle          #+#    #+#             */
/*   Updated: 2022/11/20 16:55:53 by seongyle         ###   ########seoul.kr  */
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
