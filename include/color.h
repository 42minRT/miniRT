/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:50:38 by seongyle          #+#    #+#             */
/*   Updated: 2022/11/20 16:50:39 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdio.h>
# include "structures.h"

t_color3	set_color_rgb(double r, double g, double b);
t_color3	red(void);
t_color3	green(void);
t_color3	blue(void);
t_color3	white(void);
t_color3	black(void);

#endif
