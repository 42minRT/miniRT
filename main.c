#include "parse.h"

int	print_error(t_error err)
{
	const char	*arg_msg = "wrong file.\n";
	const char	*ele_msg = "wrong elements in file.\n";
	const char	*sys_msg = "file open fail.\n";

	write(1, "Error\n", 6);
	if (err == ARG_ERROR)
		write(1, arg_msg, ft_strlen(arg_msg));
	if (err == ELEMENTS_ERROR)
		write(1, ele_msg, ft_strlen(ele_msg));
	if (err == SYSTEM_ERROR)
		write(1, sys_msg, ft_strlen(sys_msg));
	while (1)
	{
		;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_error	err;
	t_list	*file;

	file = NULL;
	err = validate_file(argc, argv, &file);
	if (err != NO_ERROR)
		return (print_error(err));
	// 출력용 임시 함수
	write(1, "\n\n", 2);
	rt_lstprint(file);
	while (1)
	{
		;
	}
}