#include "mlx.h"
#include "get_next_line.h"
#include <math.h>

#define TILE_SIZE 32
#define MAP_ROWS 7
#define MAP_COLS 15
#define WINDOW_WIDTH MAP_COLS*TILE_SIZE
#define WINDOW_HEIGHT MAP_ROWS*TILE_SIZE
typedef struct  s_win
{
    void *mlx_ptr;
	void *win_ptr;
}t_win;
typedef struct  s_player
{
    int x;
	int y;
	int radius;// = 0 , -1 if left, +1 if right
	int turnd_direc;// -1 if back, +1 if front
	double walk_direc;// = M_PI/2
	double move_speed;// = 3.0
	double rotation_angl;//3 * (M_PI/180)

}t_player;
int mapgrid[MAP_ROWS][MAP_COLS]={
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
//void file_config(char *path, )
void rect_tracer(int i , int j, t_win *pxl)
{
	int x,y;

	x = j*TILE_SIZE;
	while (x < ((j+1) * TILE_SIZE))
	{
		y  = i*TILE_SIZE;
		while(y < ((i+1) * TILE_SIZE))
		{
			mlx_pixel_put(pxl->mlx_ptr,pxl->win_ptr,x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}
R_check()
{
	//resolution check
}

void render(t_win *pxl)
{
	int i;
	int j;

	i = 0;
	while (i < MAP_ROWS)
	{
		j = 0;
		while(j < MAP_COLS)
		{
			if (mapgrid[i][j] == 1)
				rect_tracer(i,j,pxl);
			j++;
		}
		i++;
	}
}
void setup(t_win *pxl)
{
	
	pxl->mlx_ptr = mlx_init();
	pxl->win_ptr = mlx_new_window(pxl->mlx_ptr, WINDOW_WIDTH,WINDOW_HEIGHT,"mlx 42");
	//initialize all objects
	
}

void update(t_win *pxl)
{
	// update all game objects before we render the next frame
}

void draw(t_win *pxl)
{
	update(pxl);
	render(pxl);
}

int main()
{	
	int i,x,y;
	int j;
	t_win pxl;

	setup(&pxl);
	render(&pxl);
    mlx_loop(pxl.mlx_ptr);
    return (0);
}
//gcc -I /usr/X11/include/X11 -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit main.c
	//gcc -I /usr/local/include -g -L /usr/local/lib -l mlx -framework OpenGL -framework AppKit main.c && ./a.out
	//mlx_pixel_put(pxl.mlx_ptr,pxl.win_ptr,10, 10, 0xFFFFFF);
	
	//mlx_pixel_put	
	//void *mlx_ptr;
	//void *win_ptr;
	//mlx_ptr = mlx_init();
	//win_ptr = mlx_new_window(mlx_ptr, 500,500,"mlx 42");
	/*M_E
	[XSI] [Option Start] Value of e
	M_LOG2E
	Value of log2e
	M_LOG10E
	Value of log10e
	M_LN2
	Value of loge2
	M_LN10
	Value of loge10
	M_PI
	Value of 
	M_PI_2
	Value of /2
	M_PI_4
	Value of /4
	M_1_PI
	Value of 1/
	M_2_PI
	Value of 2/
	M_2_SQRTPI
	Value of 2/ 
	M_SQRT2
	Value of 2
	M_SQRT1_2
	Value of 1/2 [Option End]*/