/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:25:51 by jaekim            #+#    #+#             */
/*   Updated: 2022/11/10 19:25:52 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/structures.h"

void	free_splited(char **target)
{
	int	i;

	i = 0;
	while (target && target[i])
	{
		free(target[i]);
		++i;
	}
	if (target)
		free(target);
}

t_is_return	free_return(char **target, t_is_return boolean)
{
	int	i;

	i = 0;
	while (target && target[i])
	{
		free(target[i]);
		++i;
	}
	if (target)
		free(target);
	return (boolean);
}
