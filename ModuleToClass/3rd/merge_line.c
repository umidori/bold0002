#include <stdio.h>
#include <string.h>
#include "get_line1.h"
#include "get_line2.h"

int main(void)
{
    char *line1, *line2;

    init_line1("a.txt");
    init_line2("b.txt");

    line1 = get_line1();
    line2 = get_line2();
    while (line1 != NULL && line2 != NULL) {
        if (strcmp(line1, line2) < 0) {
            printf("[%s]\n", line1);
            line1 = get_line1();
        } else {
            printf("[%s]\n", line2);
            line2 = get_line2();
        }
    }
    while (line1 != NULL) {
        printf("[%s]\n", line1);
        line1 = get_line1();
    }
    while (line2 != NULL) {
        printf("[%s]\n", line2);
        line2 = get_line2();
    }

    del_line1();
    del_line2();

    return 0;
}
