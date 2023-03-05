#include <stdio.h>
#include <string.h>
#include "get_line.h"

int main(void)
{
    char *line1, *line2;

    Fline f1("a.txt");
    Fline f2("b.txt");

    line1 = f1.get_line();
    line2 = f2.get_line();
    while (line1 != NULL && line2 != NULL) {
        if (strcmp(line1, line2) < 0) {
            printf("[%s]\n", line1);
            line1 = f1.get_line();
        } else {
            printf("[%s]\n", line2);
            line2 = f2.get_line();
        }
    }
    while (line1 != NULL) {
        printf("[%s]\n", line1);
        line1 = f1.get_line();
    }
    while (line2 != NULL) {
        printf("[%s]\n", line2);
        line2 = f2.get_line();
    }

    return 0;
}
