#include <stdio.h>
#include <stdlib.h>

static const int init_size = 1;
static int cap = 0;
static char *line = NULL;
static int endofline(FILE *fp, int c);
static char *get_line(FILE *fp);

int main(void)
{
    char *line;
    FILE *fp;

    fp = fopen("a.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "File open error!\n");
        exit(1);
    }

    while ((line = get_line(fp)) != NULL) {
        printf("[%s]\n", line);
    }

    fclose(fp);
    free(line);

    return 0;
}

static int endofline(FILE *fp, int c)
{
    int eol;

    eol = (c == '\r' || c == '\n');

    if (c == '\r') {
        c = getc(fp);
        if (c != '\n' && c != EOF) {
            ungetc(c, fp);
        }
    }

    return eol;
}

static char *get_line(FILE *fp)
{
    int i, c;
    char *newl;

    if (line == NULL) {
        cap = init_size;
        line = (char *)malloc(cap);
        if (line == NULL) {
            cap = 0;
            return NULL;
        }
    }

    for (i = 0; (c = getc(fp)) != EOF && !endofline(fp, c); i++) {
        if (i >= cap - 1) {
            cap *= 2;
            newl = (char *)realloc(line, cap);
            if (newl == NULL) {
                free(line);
                cap = 0;
                return NULL;
            }
            line = newl;
        }
        line[i] = c;
    }
    line[i] = '\0';

    return (c == EOF && i == 0) ? NULL : line;
}
