#include <stdio.h>

class Fline {
private:
    int cap;
    char *line;
    FILE *fp;
public:
    Fline(const char *fname);
    char *get_line();
    ~Fline();
};

