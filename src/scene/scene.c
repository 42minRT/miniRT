/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:53:15 by seongyle          #+#    #+#             */
/*   Updated: 2022/11/20 16:55:46 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/scene.h"
#include "../../include/utils.h"

t_color3	set_ambient(char **ambient_values)
{
	t_color3	ambient;

	ambient = vmult(parse_rgb(ambient_values[1]),
			ft_atod(ambient_values[0]));
	return (ambient);
}

void	set_cam_coordination(t_vec3 *u, t_vec3 *v, t_vec3 *w)
{
	*v = vunit(vcross(*w, vup(*w)));
	*u = vunit(vcross(*w, *v));
}

t_camera	set_camera(t_canvas *canvas, char **elements)
{
	t_camera	cam;
	double		viewport_height;

	viewport_height = 2.0;
	cam.origin = parse_xyz_coordination(elements[0]);
	cam.w_dir = parse_vec3(elements[1]);
	set_cam_coordination(&cam.u_dir, &cam.v_dir, &cam.w_dir);
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.focal_len = get_focal_len(cam.viewport_w, ft_atoi(elements[2]));
	cam.horizontal = vmult(cam.u_dir, cam.viewport_w);
	cam.vertical = vmult(cam.v_dir, cam.viewport_h);
	cam.left_bottom = vminus(
			vminus(vminus(cam.origin, vdivide(cam.horizontal, 2)), \
			vdivide(cam.vertical, 2)), vmult(cam.w_dir, -1 * cam.focal_len));
	return (cam);
}
