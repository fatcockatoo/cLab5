#include <stdio.h>

void strcpy(char* dest, int len, const char* src)
{
    int ssize = 0;
    while (src[ssize]) ssize++;
    for (int j = 0; j < ssize; j++) {
        if (j != len - 1)
            dest[j] = src[j];
        else {
            dest[j] = '\0';
            break;
        }
    }
    return;
}

void main()
{
    const char src[255] = "qweertyuvfjddhgtjhgfyjlczaxn";
    const int len = 5;
    char dest[5];
    printf("%s\n", src);
    strcpy(dest, len, src);
    printf("%s", dest);
}
