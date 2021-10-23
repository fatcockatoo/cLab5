#include <stdio.h>

int strlen(const char* str)
{
    int i = 0;
    while (str[i]) i++;
    return i;
}

void main()
{
    const char str[255] = "yjjtghgfjhfjygfjghj";
    int res = strlen(&str);
    printf("%d", res);
}
