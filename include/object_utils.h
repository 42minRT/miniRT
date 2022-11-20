/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:50:52 by seongyle          #+#    #+#             */
/*   Updated: 2022/11/20 16:50:52 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_UTILS_H
# define OBJECT_UTILS_H

# include <stdlib.h>
# include "structures.h"

void		object_append(t_object **list, t_object *new_obj);
t_object	*object_last(t_object *list);

#endif
