/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:54:06 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/11/05 11:54:08 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <limits.h>
# include <stdint.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <float.h>

# define BUFFER_SIZE    4096

# define MLX_ERROR 0

# define MY_PI 3.14159265
# define MY_TWO_PI 6.28318530

# define FPS 60

# define TILE_SIZE 64

# define NUM_TEXTURES 8

# define MINIMAP_SCALE_FACTOR 0.2

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 800

# define FOV_ANGLE 1.04719755

# define NUM_RAYS WINDOW_WIDTH

typedef struct s_cast
{
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_right;
	int		is_ray_facing_left;
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;
	int		found_horz_wall_hit;
	float	horzwall_hit_x;
	float	horzwall_hit_y;
	int		horz_wall_content;
	float	next_horz_touch_x;
	float	next_horz_touch_y;
	float	x_to_check;
	float	y_to_check;
	int		found_vert_wall_hit;
	float	vert_wall_hit_x;
	float	vert_wall_hit_y;
	int		vert_wall_content;
	float	next_vert_touch_x;
	float	next_vert_touch_y;
	float	horz_hit_dist;
	float	vert_hit_dist;
}	t_cast;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
}	t_img;

typedef struct s_text
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_text;

typedef struct ft_render_map
{
	int		text_num;
	float	perp_distance;
	float	dist_proj_plane;
	float	proj_wall_height;
	int		wall_strip_height;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	int		dist_from_top;
	int		texture_offset_y;
	char	*texel_color;
	int		texture_offset_x;
}	t_render;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rect;

typedef struct s_line
{
	int		begin_x;
	int		begin_y;
	int		end_x;
	int		end_y;
	int		color;
}	t_line;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;
	int		walk_side;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
}	t_player;

typedef struct s_rays
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vert;
	int		is_ray_facing_up;
	int		is_ray_facing_down;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
	int		wall_hit_content;
}	t_rays;

typedef struct s_datar
{
	int			i;
	int			f;
	int			c;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			nblines;
	int			sizeline;
	int			**map;
	char		depart;
	int			dx;
	int			dy;
	int			indicateur;
	int			indicateur2;
	int			indicateur3;
	int			erreur;
	int			multijoueurs;
	int			lignevide;
	int			insidemap;
	int			count;
	int			count2;
	int			sum;
	int			wrongcharmap;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_text		texture[4];
	t_rays		rays[NUM_RAYS];
	t_player	player;
}	t_datar;

void	ft_initialisation(t_datar *recup);
void	ft_init_more(t_datar *recup);
int		ft_cub(char *str, t_datar *recup);
void	ft_error(t_datar *recup, char *str);
int		ft_exit(t_datar *recup);
void	ft_parsing(char *fichier, t_datar *recup);
int		get_next_line(int fd, char **line, t_datar *recup);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_subbuff(char *buff, int start, int len);
void	ft_color_resolution(char **str, t_datar *recup);
int		ft_atoi4(const char *str, t_datar *recup);
int		ft_charinstr(char *str, char c);
void	ft_atoi3_check(const char *str, t_datar *recup);
int		ft_nb_virgule(const char *str);
int		ft_strlen2(char *str);
void	ft_map(char *str, t_datar *recup);
int		ft_is_map(char *str, t_datar *recup);
int		ft_parsing_map(char *fichier, t_datar *recup);
int		ft_lignevide(char *str);
int		ft_copy_map(char *str, t_datar *recup);
int		ft_depart(char c, t_datar *recup, int i, int j);
void	ft_verify_errors(t_datar *recup);
int		ft_murs(t_datar *recup);
int		ft_murs_util(int *str);
void	ft_texture(char *str, t_datar *recup);
int		ft_handle_destroynotify(t_datar *data);
int		ft_mlx(t_datar *data);
int		ft_init(t_datar *data);
void	ft_setup(t_datar *data);
void	ft_img_pix_put(t_img *img, int x, int y, int color);
void	ft_render_wall(t_datar *data);
int		ft_render_rect(t_img *img, t_rect rect);
int		ft_draw_line(t_img *img, t_line line);
void	ft_render_background(t_datar *data, int color);
void	ft_render_player(t_datar *data);
void	ft_render_map(t_datar *data);
int		ft_map_has_wall_at(t_datar *recup, float x, float y);
float	ft_dist_bet_points(float x1, float y1, float x2, float y2);
void	ft_normalize_angle(float *angle);
void	ft_cast_ray(t_datar *data, float ray_angle, int stripId);
void	ft_cast_rays(t_datar *data);
void	ft_render_rays(t_datar *data);
int		ft_handle_keypress(int keysym, t_datar *data);
int		ft_handle_keyrelease(int keysym, t_datar *data);
int		ft_test_str(char str);
int		ft_test_str2(char str);
void	ft_render_wall_setup(t_datar *data, t_render*render, int i);
void	ft_wall_pix_put(t_datar *data, t_render *render, int i);
void	ft_f_c_pix_put(t_datar *data, int i);
void	ft_texture_setup(t_datar *data, t_render *render, int i);
void	ft_cast_ray_init(t_datar *data, t_cast *ray, float ray_angle);
void	ft_horz_touch(t_datar *data, t_cast *ray);
void	ft_vert_touch(t_datar *data, t_cast *ray, float ray_angle);
void	ft_data_rays(t_datar *data, t_cast *ray, float ray_angle, int strip_id);
void	ft_cast_ray_init_next(t_datar *data, t_cast *ray, float ray_angle);
int		ft_map_dir_rony_check(char *fichier, t_datar *recup);
void	ft_swap_line(char **line, char *temp);
int		ft_gnl_cpy(int ret, char *buff, char **line);
int		ft_copy(char **line, char **buff);
void	ft_map_copy(t_datar *recup, char *str);
int		ft_glitch(t_datar *data);
int		ft_glitch_inverse(t_datar *data, int map_grid_x, int map_grid_y);
#endif
