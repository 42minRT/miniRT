#include "../include/parse.h"
#include "../include/print.h"
#include "../include/structures.h"
#include "../include/vector_utils.h"
#include "../include/object_utils.h"
#include "../include/write_color.h"
#include "../include/scene.h"
#include "../include/trace.h"

int	main(void)
{
    int			i;
    int			j;
    double      u;
    double      v;
	t_color3	pixel_color;
    t_object    *world;
    t_scene     *scene;

    scene = scene_init();
    // 랜더링
    // P3 는 색상값이 아스키코드라는 뜻, 그리고 다음 줄은 캔버스의 가로, 세로 픽셀 수, 마지막은 사용할 색상값
    printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
    j = scene->canvas.height - 1;
    while (j >= 0)
    {
        i = 0;
        while (i < scene->canvas.width)
        {
            u = (double)i / (scene->canvas.width - 1);
            v = (double)j / (scene->canvas.height - 1);
            scene->ray = ray_primary(&scene->camera, u, v);
            pixel_color = ray_color(scene);
			write_color(pixel_color);
            ++i;
        }
    --j;
    }
    return (0);
}
/*
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
*/
