#include "../../include/window.h"

void	handle_key(int keycode)
{
	if (keycode == KEY_ESC)
		close_window(0);
}

void	close_window(int status)
{
	exit(status);
}
