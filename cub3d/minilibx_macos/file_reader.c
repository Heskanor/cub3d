#include "get_next_line.h"
#define BUFFER_SIZE 30
typedef struct  s_map
{
    char *s;
    int f_color;
    int c_color;
    int width;
    int height;



    
    
}t_map;


int rgb_to_int(int r,int g,int b)
{
    retun ((r&0x0ff)<<16)|((g&0x0ff)<<8)|(b&0x0ff);
}
int checker(t_map map, char *s)
{
    int i,j,fd,
    i =1;
    j = 0;
    while (i != 0)
    {
        i=get_nextline(fd,&s);//empty line ?
        if ()
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