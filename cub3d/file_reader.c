#include "get_next_line.h"
#define BUFFER_SIZE 30
typedef struct  s_map
{
    char *s;
    int f_color;
    int fd, r,no,so,we,ea,s,f,c;
    int c_color;
    int width;
    int height;
    char *no_text;
    char *so_text;
    char *we_text;
    char *ea_text;
    int i,j;
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
  map->j = 0;
  map->i = 0;
}
int rgb_to_int(int r,int g,int b)
{
    retun ((r&0x0ff)<<16)|((g&0x0ff)<<8)|(b&0x0ff);
}
int check_empty(char *s)
{
  int i;

  i = 0;
  while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
			|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
  if (s[i] == '\0') //empty
    return 1;
  else if (s[i] = '1')// map start
    return 2;
  else                // error
    return 0;
}
void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
		write(1, s, i);
	}
}
int checker(t_map *map, char *s)
{
  int j,r,e,len;

  j = 0;
  r = 0;
  e = check_empty(s);
  if (r < 0)
    return (r);
  if (r < 8 && e == 0)
  {
    if (s[0] == 'R')
      r_checker(map,s,&r); 
    else if (s[0] == 'N' || s[0] == 'S' || s[0] == 'W'|| s[0] == 'E')
      no_checker(map,s,&r);
    else if (s[0] == 'F' || s[0] == 'C')
      clor_checker(map, s, &r);
  }
  else if (r == 8 && e == 2)
  { 
    r = 9;
    len = ft_strlen(s);
    map->i =(len > map->i) ? len : map->i;
    map->j++;
  
  }else if( r < 8 && e == 2)
  {
    ft_putstr("Error \n manque de parametres");
    return 1;
  }
  return (0);
}
int ft_error(int i)
{
/* 
** -1 need an option
** -2 incorrect resolution
** -3 incorrect north texture
** -4 incorrect soth texture
** -5 incorrect west texture
** -6 incorrect east texture
** -7 incorrect sprite texture
** -8 incorrect Floor color
** -9 incorrect Celling color
** -10 incorrect map
** 0 wp :)
*/


}
int two_repeat(t_map *map)
{
  int i;
  char *s;
  i = 1;

  initializer(map);
  while (i != 0)
    {
       
        i=get_nextline(map->fd,&s);//empty line ?
        checker(map, s);
        
        free(s);
    }
}
int file_reader(t_map *map)
{
    int i,rgb;
    int r,g,b;
    char *s;
    
    map->fd = open("map.cub",O_RDONLY);
    return (ft_error(two_repeat(&map)));
    
    close(map->fd);
/*
** Read all file 
*/
    

/*
** check Resolution errors
** returns: A pointer to the located character
** NULL otherwise
*/
}
