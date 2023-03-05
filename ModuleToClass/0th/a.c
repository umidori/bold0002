#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    char line[10];

    if ((fp = fopen("a.txt", "r")) == NULL) {
        fprintf(stderr, "File open error!\n");
        exit(1);
    } 

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("[%s]", line);
    }

    return 0;
}
