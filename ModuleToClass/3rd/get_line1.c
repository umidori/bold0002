#include <stdio.h>
#include <stdlib.h>
#include "get_line1.h"

static const int init_size = 1;

static int cap = 0;
static char *line = NULL;
static FILE *fp = NULL;

static int endofline(FILE *fp, int c);

void init_line1(char *fname)
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

char *get_line1(void)
{
    int i, c;
    char *newl;

    for (i = 0; (c = getc(fp)) != EOF && !endofline(fp, c); i++) {
        if (i >= cap - 1) {
            cap *= 2;
            newl = (char *)realloc(line, cap);
            if (newl == NULL) {
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

void del_line1(void)
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
