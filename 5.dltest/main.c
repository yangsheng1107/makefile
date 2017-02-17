/*
 * Copyright (c) 1997 <Author>  <@>
 *
 * <Content>
 */

#include <stdlib.h>
#include <stdio.h>
#include <libgen.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    void *handle = NULL;
    int (*calc)(int, int);

    if(argc != 2) {
        printf("Usage : %s <libpath>\r\n", basename(argv[0]));
        return -1;
    }

    handle = dlopen(argv[1], RTLD_LAZY);
    if(handle == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        return -1;
    }

    calc = dlsym(handle, "calc");
    if(calc == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        return -1;
    }

    printf("%d\n", (*calc)(8, 2));

    dlclose(handle);
    handle = NULL;

    return 0;
}
