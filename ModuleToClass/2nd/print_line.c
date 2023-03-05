#include <stdio.h>
#include "get_line.h"

int main(void)
{
    char *line;

    init_line("a.txt");

    while ((line = get_line()) != NULL) {
        printf("[%s]\n", line);
    }

    del_line();

    return 0;
}
