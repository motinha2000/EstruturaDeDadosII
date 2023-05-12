#include "tree.h"
#include <string.h>

int compara(void *data1, void *data2)
{
    char *string1 = (char *)data1;
    char *string2 = (char *)data2;
    if(strcmp(string1,string2)==0)
        return true;
    else
        return false;
}

void main(void)
{
    TreeNode raiz;
    add(&raiz, 0, compara)
}