#include "parse.h"

t_error	validate_file(int argc, char **argv)
{
	int		fd;
	char	*buf;

	if (argc != 2 || is_rt_file(argv[1]) == FALSE)
		return (ARG_ERROR);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (SYSTEM_ERROR);
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		write(1, buf, ft_strlen(buf));
		free(buf);
	}
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