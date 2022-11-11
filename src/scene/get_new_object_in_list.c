/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_object_in_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:23:42 by jimin             #+#    #+#             */
/*   Updated: 2022/11/11 13:24:42 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scene.h"
#include "../../include/object_utils.h"
#include "../../include/utils.h"

t_object	*get_new_object_in_list(t_rt_list *rt_list)
{
	t_object	*object;
	void		*element;
	char		**elements;

	object = NULL;
	elements = rt_list->elements;
	if (rt_list->type == SP)
	{
		element = new_sphere(parse_vec3(elements[0]), ft_atod(elements[1]));
		object = new_object(SP, element, parse_rgb(elements[2]));
	}
	else if (rt_list->type == CY)
	{
		element = new_cylinder(parse_vec3(elements[0]),
				parse_vec3(elements[1]),
				ft_atod(elements[2]),
				ft_atod(elements[3]));
		object = new_object(CY, element, parse_rgb(elements[4]));
	}
	else if (rt_list->type == PL)
	{
		element = new_plane(parse_vec3(elements[0]), parse_vec3(elements[1]));
		object = new_object(PL, element, parse_rgb(elements[2]));
	}
	return (object);
}
