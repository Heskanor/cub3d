#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int i,rgb,fd;
    int r,g,b;
    char *s;
    
    fd = open("map.cub",O_RDONLY);

    r= 195;
    g= 10;
    b= 77;
    rgb = ((r&0x0ff)<<16)|((g&0x0ff)<<8)|(b&0x0ff);
    printf("%d",rgb);
}