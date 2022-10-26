#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "libft.h"


// error number
typedef enum e_error
{
	NO_ERROR = 0,
	ERROR = 1,
	ARG_ERROR = 100,
	ELEMENTS_ERROR = 101,
	SYSTEM_ERROR = 102
}	t_error;

//boolean 값
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

// is 함수의 return 값을 yes, no 로 받으세요
typedef enum e_is_return
{
	NO,
	YES
}	t_is_return;

//	object_type 정리함. EPSILON 은 int 가 아니라 뺌
typedef enum e_object_type
{
	SP = 0,
	LIGHT_POINT,
	LUMEN
}	t_object_type;

# define EPSILON 1e-6

// t_list 였던 것. 겹쳐서 t_rt_list 로 변경.
typedef struct s_rt_list	t_rt_list;
struct s_rt_list
{
	char	*type;
	char	**elements;
	t_rt_list	*next;
};

// mlx img
typedef struct s_data	t_data;
struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_vec3	t_color3;
typedef struct s_ray	t_ray;
typedef struct s_camera	t_camera;
typedef struct s_canvas	t_canvas;
typedef	struct s_sphere	t_sphere;
typedef struct s_hit_record	t_hit_record;
typedef struct s_object	t_object;
typedef struct s_scene	t_scene;
typedef struct s_light	t_light;
typedef struct s_color	t_color;


struct s_vec3
{
	double x;
	double y;
	double z;
};

struct s_ray
{
	t_point3	origin;
	t_vec3		dir;
};

struct s_camera
{
	t_point3	origin;
	double		viewport_h;
	double		viewport_w;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_len;
	t_point3	left_bottom;
};

struct	s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct	s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct s_color3
{
	double x;
	double y;
	double z;
};

struct s_color
{
	double r;
	double g;
	double b;
};

struct	s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
};

struct	s_object
{
	t_object_type	type;
	void			*element;
	void			*next;
	t_color3		albedo;
};

struct s_light
{
    t_point3    origin;
    t_color3    light_color;
    double      bright_ratio;
};

struct s_scene
{
    t_canvas        canvas;
    t_camera        camera;
    t_object        *world;
    t_object        *light;
    t_color3        ambient;
    t_ray           ray;
    t_hit_record    rec;
};


#endif
