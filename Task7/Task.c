#include <stdio.h>
#include <stdbool.h>

int strlen(const char* str)
{
    int i = 0;
    while (str[i]) i++;
    return i;
}

void task1()
{
    const char str[255] = "yjjtghgfjhfjygfjghj";
    int res = strlen(&str);
    printf("%d", res);
}

char* find(const char* str, const char* substr)
{
    int i = 0;
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
        if (*sbs == '\0')
            return i;
        if (*s == '\0')
            return 0;
        str++;
        i++;
    }
    return 0;
}

void task2()
{
    const char str[255] = "ytbjyjjtghgfjhfjygfjghj", substr[255] = "hfjygf";
    char* res = find(&str, &substr);
    printf("%d", res);
}

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
            for (int j = pos - 1; j < ssize; j++) {
                if (j <= ssize - sbsize)
                    str[j] = str[j + sbsize];
                else {
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

void task3()
{
    char str[255] = "qweertyuvfjyjlczaxn";
    const char substr[255] = "weert";
    printf("%s\n", str);
    delete(&str, &substr);
    printf("%s", str);
}

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


void task4()
{
    const char src[255] = "qweertyuvfjddhgtjhgfyjlczaxn";
    const int len = 5;
    char dest[5];
    printf("%s\n", src);
    strcpy(dest, len, src);
    printf("%s", dest);
}

void strcat(char* dest, int len, const char* first, const char* second)
{
    for (int j = 0; j <= strlen(first); j++) {
        if (j != len - 1)
            dest[j] = first[j];
        else {
            dest[j] = '\0';
            return;
        }
    }
    for (int j = strlen(first); j <= strlen(second) + strlen(first); j++) {
        if (j != len - 1)
            dest[j] = second[j - strlen(first)];
        else {
            dest[j] = '\0';
            return;
        }
    }

}
void task5()
{
    const char first[255] = "qwedgte";
    const char second[255] = "irgsgfhg";
    int len = 15;
    char dest[15];
    printf("%s\n", first);
    printf("%s\n", second);
    strcat(dest, len, first, second);
    printf("%s", dest);
}

bool insert(const char* src, const char* str, int index, char* dest, int len)
{
    if (strlen(src) + strlen(str) > len || index > strlen(src))
        return 0;
    for (int j = 0; j < strlen(src) + strlen(str); j++) {
        if (j <= index)
            dest[j] = src[j];
        else if (j > index + strlen(str)) {
            dest[j] = src[j - strlen(str)];
        }
        else {
            dest[j] = str[j - index - 1];
        }
    }
    dest[strlen(src) + strlen(str)] = '\0';
    return 1;
}

void task6()
{
    char src[255] = "qweczaxn";
    const char str[255] = "wrt";
    int index = 4, len = 15;
    char dest[15];
    printf("%s\n", src);
    printf("%s\n", str);
    if (insert(src, str, index, dest, len))
        printf("%s", dest);
    else
        printf("sorry its error");
}