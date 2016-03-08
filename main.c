#include <stdio.h>
#include <stdint.h>

//file with source graph
extern FILE *pSrc;
extern char *pBuff; 

int
main(int argc, char* argv[]) 
{
    uint8_t ret = read_source_graph("in", pBuff);
    return 0;
}
