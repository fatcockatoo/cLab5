#include <stdio.h>

void delete (char* str, const char* substr) 
{

    int sbsize = 0;
    while (substr[sbsize]) sbsize++;
    int ssize = 0;
    while (str[ssize]) ssize++;
    ssize -= 1;
    int pos = 0;
    while (str)
    {

        const char* s = str;
        const char* sbs = substr;

        while (*s == *sbs)
        {
            s++; sbs++;
            if (*sbs == '\0' || *s == '\0')
                break;
        }
        if (*sbs == '\0') {
            for (int j = pos-1; j < ssize; j++) {
                if(j <= ssize - sbsize)
                    str[j] = str[j + sbsize];
                else{
                    str[j] = '\0';
                    break;
                }
            }
            return;
        }
        if (*s == '\0')
            return;
        str++;
        pos++;
    }
}

void main()
{
    char str[255] = "qweertyuvfjyjlczaxn";
    const char substr[255] = "weert";
    printf("%s\n", str);
    delete(&str, &substr);
    printf("%s", str);
}
