#include <stdio.h>
#include <stdlib.h>
#include "get_line.h"

static const int init_size = 1;

static int endofline(FILE *fp, int c);

Fline::Fline(const char *fname)
{
    fp = fopen(fname, "r");
    if (fp == NULL) {
        fprintf(stderr, "File open error!\n");
        exit(1);
    }

    cap = init_size;
    line = (char *)malloc(cap);
    if (line == NULL) {
        fprintf(stderr, "Memory error!\n");
        exit(1);
    }
}

char *Fline::get_line()
{
    int i, c;
    char *newl;

    for (i = 0; (c = getc(fp)) != EOF && !endofline(fp, c); i++) {
        if (i >= cap - 1) {
            cap *= 2;
            newl = (char *)realloc(line, cap);
            if (newl == NULL) {
                cap = 0;
            }
            line = newl;
        }
        line[i] = c;
    }
    line[i] = '\0';

    return (c == EOF && i == 0) ? NULL : line;
}

Fline::~Fline()
{
    fclose(fp);
    free(line);
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
