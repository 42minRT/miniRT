#include "../../include/structures.h"

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