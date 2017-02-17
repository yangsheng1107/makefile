/*
 * Copyright (c) 1997 <Author>  <@>
 *
 * <Content>
 */
#include <stdlib.h>
#include <stdio.h>
#include <libgen.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    int mode = 0;
    if(argc != 2) {
        printf("Usage : %s \r\n", basename(argv[0]));
        return -1;
    }
    mode = atol(argv[1]);

    if(mode == 0)
        printf("%d\n", add(8, 2));
    else
        printf("%d\n", sub(8, 2));

    return 0;
}
