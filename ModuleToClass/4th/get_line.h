#include <stdio.h>

typedef struct {
    int cap;
    char *line;
    FILE *fp;
} Fline;

void init_line(Fline *fl, char *fname);
char *get_line(Fline *fl);
void del_line(Fline *fl);
