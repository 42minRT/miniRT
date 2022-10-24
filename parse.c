#include "parse.h"

t_error	validate_file(int argc, char **argv)
{
	if (argc != 2 || is_rt_file(argv[1]) == FALSE)
		return (ARG_ERROR);
	return (NO_ERROR);
}

t_bool	is_rt_file(char *file_name)
{
	int		len;
	char	*file_ext;
	t_bool	match;

	match = FALSE;
	len = ft_strlen(file_name);
	file_ext = ft_substr(file_name, len - 3, 3);
	if (ft_strncmp(file_ext, ".rt", 3) == 0)
		match = TRUE;
	free(file_ext);
	return (match);
}