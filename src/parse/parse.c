#include "../../include/parse.h"

t_error	parse_file(int argc, char **argv, t_rt_list **file)
{
	int		fd;
	char	*buf;

	if (argc != 2 || is_rt_file(argv[1]) == NO)
		return (ARG_ERROR);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (SYSTEM_ERROR);
	*file = NULL;
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		write(1, buf, ft_strlen(buf));
		if (parse_elements(buf, file) == FALSE)
			return (ELEMENTS_ERROR);
		free(buf);
	}
	return (NO_ERROR);
}
