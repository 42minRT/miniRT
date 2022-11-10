/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:27:19 by jaekim            #+#    #+#             */
/*   Updated: 2022/11/10 19:27:19 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structures.h"
#include "../../include/vector_utils.h"
#include "../../include/utils.h"

char	**get_elements_by_type(t_rt_list *file, t_object_type type)
{
	while (file)
	{
		if (file->type == type)
			return (file->elements);
		file = file->next;
	}
	return (NULL);
}

t_point3	parse_xyz_coordination(char *xyz_str)
{
	char		**xyz;
	double		x;
	double		y;
	double		z;
	t_point3	xyz_coordination;

	xyz = ft_split(xyz_str, ',');
	x = ft_atod(xyz[0]);
	y = ft_atod(xyz[1]);
	z = ft_atod(xyz[2]);
	xyz_coordination = point3(x, y, z);
	free_splited(xyz);
	return (xyz_coordination);
}

t_color3	parse_rgb(char *rgb_str)
{
	char		**rgb;
	double		r;
	double		g;
	double		b;
	t_color3	rgb_color;

	rgb = ft_split(rgb_str, ',');
	r = ft_atod(rgb[0]);
	g = ft_atod(rgb[1]);
	b = ft_atod(rgb[2]);
	rgb_color = color3((double)(r / 255), (double)(g / 255), (double)(b / 255));
	free_splited(rgb);
	return (rgb_color);
}

t_vec3	parse_vec3(char *vector_str)
{
	char		**xyz;
	double		x;
	double		y;
	double		z;
	t_vec3		xyz_vector;

	xyz = ft_split(vector_str, ',');
	x = ft_atod(xyz[0]);
	y = ft_atod(xyz[1]);
	z = ft_atod(xyz[2]);
	xyz_vector = vec3(x, y, z);
	free_splited(xyz);
	return (xyz_vector);
}
