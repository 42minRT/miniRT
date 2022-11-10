/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rt_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:28:21 by jaekim            #+#    #+#             */
/*   Updated: 2022/11/10 19:28:22 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/parse.h"

t_is_return	is_rt_file(char *file_name)
{
	int			len;
	char		*file_ext;
	t_is_return	match;

	match = NO;
	len = ft_strlen(file_name);
	file_ext = ft_substr(file_name, len - 3, 3);
	if (ft_strncmp(file_ext, ".rt", 3) == 0)
		match = YES;
	free(file_ext);
	return (match);
}
