#include "../../include/print.h"
#include <unistd.h>

int	print_error(t_error err)
{
	const char	*arg_msg = "wrong file.\n";
	const char	*ele_msg = "wrong elements in file.\n";
	const char	*sys_msg = "file open fail.\n";

	write(STDOUT_FILENO, "Error\n", 6);
	if (err == ARG_ERROR)
		write(STDOUT_FILENO, arg_msg, ft_strlen(arg_msg));
	if (err == ELEMENTS_ERROR)
		write(STDOUT_FILENO, ele_msg, ft_strlen(ele_msg));
	if (err == SYSTEM_ERROR)
		write(STDOUT_FILENO, sys_msg, ft_strlen(sys_msg));
	// while (TRUE)
	// {
	// 	;
	// }
	return (ERROR);
}
