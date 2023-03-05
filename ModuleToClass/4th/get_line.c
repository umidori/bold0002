#include <stdio.h>
#include <stdlib.h>
#include "get_line.h"

static const int init_size = 1;

static int endofline(FILE *fp, int c);

void init_line(Fline *fl, char *fname)
{
    fl->fp = fopen(fname, "r");
    if (fl->fp == NULL) {
        fprintf(stderr, "File open error!\n");
        exit(1);
    }

    fl->cap = init_size;
    fl->line = (char *)malloc(fl->cap);
    if (fl->line == NULL) {
        fprintf(stderr, "Memory error!\n");
        exit(1);
    }
}

char *get_line(Fline *fl)
{
    int i, c;
    char *newl;

    for (i = 0; (c = getc(fl->fp)) != EOF && !endofline(fl->fp, c); i++) {
        if (i >= fl->cap - 1) {
            fl->cap *= 2;
            newl = (char *)realloc(fl->line, fl->cap);
            if (newl == NULL) {
                fl->cap = 0;
            }
            fl->line = newl;
        }
        fl->line[i] = c;
    }
    fl->line[i] = '\0';

    return (c == EOF && i == 0) ? NULL : fl->line;
}

void del_line(Fline *fl)
{
    fclose(fl->fp);
    free(fl->line);
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
