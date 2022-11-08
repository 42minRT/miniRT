#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "libft.h"

// mlx event key
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_CLOSE 17
# define KEY_ESC 53

# define EPSILON 1e-6
# define LUMEN 3

// error number
typedef enum e_error
{
	NO_ERROR = 0,
	ERROR,
	ARG_ERROR,
	ELEMENTS_ERROR,
	SYSTEM_ERROR
}	t_error;

//boolean
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

// yes, no
typedef enum e_is_return
{
	NO,
	YES
}	t_is_return;

//	object_type
typedef enum e_object_type
{
	NO_OBJECT,
	A,
	C,
	L,
	SP,
	PL,
	CY,
}	t_object_type;

typedef struct s_rt_list	t_rt_list;
struct s_rt_list
{
	t_object_type	type;
	char			**elements;
	t_rt_list		*next;
};

// mlx img
typedef struct s_data		t_data;
struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx_ptr;
	void	*win_ptr;
};

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;

// ray
typedef struct s_ray		t_ray;

// scene
typedef struct s_scene		t_scene;
typedef struct s_canvas		t_canvas;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_hit_record	t_hit_record;

// object
typedef struct s_object		t_object;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_ray
{
	t_point3	origin;
	t_vec3		dir;
};

struct s_camera
{
	t_point3	origin;
	t_vec3		u_dir;
	t_vec3		v_dir;
	t_vec3		w_dir;
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

struct s_color3
{
	double	x;
	double	y;
	double	z;
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

struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_light			*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
};

// object 구조체
struct	s_object
{
	t_object_type	type;
	void			*element;
	t_color3		albedo;
	void			*next;
};

struct	s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct s_plane
{
	t_point3	origin;
	t_vec3		dir_v;
};

struct s_cylinder
{
	t_point3	origin;
	t_vec3		dir_v;
	double		diameter;
	double		height;
};

// quadratic 
typedef struct s_quadratic t_quadratic;

struct s_quadratic
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
};

#endif
