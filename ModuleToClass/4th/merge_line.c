#include <stdio.h>
#include <string.h>
#include "get_line.h"

int main(void)
{
    char *line1, *line2;
    Fline fl1, fl2;

    init_line(&fl1, "a.txt");
    init_line(&fl2, "b.txt");

    line1 = get_line(&fl1);
    line2 = get_line(&fl2);
    while (line1 != NULL && line2 != NULL) {
        if (strcmp(line1, line2) < 0) {
            printf("[%s]\n", line1);
            line1 = get_line(&fl1);
        } else {
            printf("[%s]\n", line2);
            line2 = get_line(&fl2);
        }
    }
    while (line1 != NULL) {
        printf("[%s]\n", line1);
        line1 = get_line(&fl1);
    }
    while (line2 != NULL) {
        printf("[%s]\n", line2);
        line2 = get_line(&fl2);
    }

    del_line(&fl1);
    del_line(&fl2);

    return 0;
}
