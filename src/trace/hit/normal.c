/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:23:01 by jimin             #+#    #+#             */
/*   Updated: 2022/11/11 13:24:25 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/trace.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	if (rec->front_face == FALSE)
		rec->normal = vmult(rec->normal, -1);
}
