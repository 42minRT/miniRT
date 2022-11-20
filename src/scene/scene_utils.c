/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:53:13 by seongyle          #+#    #+#             */
/*   Updated: 2022/11/20 16:55:21 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scene.h"
#include "../../include/utils.h"

double	theta_to_radian(double theta)
{
	return (theta * M_PI / 180.0);
}

double	get_focal_len(double viewport_w, int fov)
{
	double	radian;
	double	a;
	double	b;

	radian = theta_to_radian(fov / 2.0);
	a = viewport_w / 2;
	b = tan(radian);
	return (a / b);
}

t_light	*get_new_light(char **elements)
{
	t_light	*light;

	light = new_light(parse_vec3(elements[0]),
			ft_atod(elements[1]),
			parse_rgb(elements[2]));
	return (light);
}
