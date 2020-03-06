#include "get_next_line.h"
#define BUFFER_SIZE 30
typedef struct  s_map
{
    char *s;
    int f_color;
    int r,no,so,we,ea,s,f,c;
    int c_color;
    int width;
    int height;
    char *no_text;
    char *so_text;
    char *we_text;
    char *ea_text;
    int **map;
}t_map;

initializer(t_map *map)
{
  map->r = 0;
  map->no = 0;
  map->so = 0;
  map->we = 0;
  map->ea = 0;
  map->s = 0;
  map->f = 0;
  map->c = 0;
  map->f_color = 0;
  map->c_color = 0;
  map->width = 0;
  map->height = 0;

}
int rgb_to_int(int r,int g,int b)
{
    retun ((r&0x0ff)<<16)|((g&0x0ff)<<8)|(b&0x0ff);
}
int checker(t_map *map, char *s)
{
    int i,j,fd,r;
    i =1;
    j = 0;
    r = 0;

    initializer(map);
    while (i != 0)
    {
        i=get_nextline(fd,&s);//empty line ?
        if (r < 8)
        {
          if (s[0] == 'R')
            r_checker(map,s,&r); 
          else if (s[0] == 'N' || s[0] == 'S' || s[0] == 'W'|| s[0] == 'E')
            no_checker(map,s);
          else if (s[0] == 'F' || s[0] == 'C')
            clor_checker(s);
          else if(check_empty() == )//check empty if yes go else exit_erno
            //check_empty line
             // ifgo 
                //else erno
        }
        else
        {

        }

        free(s);
    }
}
t_map file_reader()
{
    int i,rgb,fd;
    int r,g,b,error;
    char *s;
    t_map map;
    
    fd = open("map.cub",O_RDONLY);
    

    close(fd);
/*
** Read all file 
*/
    

/*
** check Resolution errors
** returns: A pointer to the located character
** NULL otherwise
*/
}
