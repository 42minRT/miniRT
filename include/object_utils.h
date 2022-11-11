/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:23:13 by jimin             #+#    #+#             */
/*   Updated: 2022/11/11 17:23:43 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_UTILS_H
# define OBJECT_UTILS_H

# include <stdlib.h>
# include "structures.h"

void		object_append(t_object **list, t_object *new_obj);
t_object	*object_last(t_object *list);

#endif
