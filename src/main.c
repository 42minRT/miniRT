#include "../include/parse.h"
#include "../include/print.h"


int	main(int argc, char **argv)
{
	t_error	err;
	t_rt_list	*file;

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
