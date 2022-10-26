/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:05:00 by jimin             #+#    #+#             */
/*   Updated: 2021/12/08 12:38:45 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	s1_uc = (unsigned char *) s1;
	s2_uc = (unsigned char *) s2;
	while (n)
	{
		if (*s1_uc != *s2_uc)
			return (*s1_uc - *s2_uc);
		s1_uc++;
		s2_uc++;
		n--;
	}
	return (0);
}
