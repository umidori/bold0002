#include <stdio.h>
#include <stdlib.h>
#include "get_line.h"

static const int init_size = 1;

static int endofline(FILE *fp, int c);

void init_line(Fline *this, char *fname)
{
    this->fp = fopen(fname, "r");
    if (this->fp == NULL) {
        fprintf(stderr, "File open error!\n");
        exit(1);
    }

    this->cap = init_size;
    this->line = (char *)malloc(this->cap);
    if (this->line == NULL) {
        fprintf(stderr, "Memory error!\n");
        exit(1);
    }
}

char *get_line(Fline *this)
{
    int i, c;
    char *newl;

    for (i = 0; (c = getc(this->fp)) != EOF && !endofline(this->fp, c); i++) {
        if (i >= this->cap - 1) {
            this->cap *= 2;
            newl = (char *)realloc(this->line, this->cap);
            if (newl == NULL) {
                this->cap = 0;
            }
            this->line = newl;
        }
        this->line[i] = c;
    }
    this->line[i] = '\0';

    return (c == EOF && i == 0) ? NULL : this->line;
}

void del_line(Fline *this)
{
    fclose(this->fp);
    free(this->line);
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
