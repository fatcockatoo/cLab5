#include <stdio.h>
#include <stdbool.h>

int strlen(const char* str)
{
    int i = 0;
    while (str[i]) i++;
    return i;
}

bool insert(const char* src, const char* str, int index, char* dest, int len)
{
    if (strlen(src) + strlen(str) > len || index > strlen(src))
        return 0;
    for (int j = 0; j < strlen(src)+ strlen(str); j++) {
        if (j <= index)
            dest[j] = src[j];
        else if (j > index + strlen(str)){
            dest[j] = src[j - strlen(str)];
    }
        else {
            dest[j] = str[j - index - 1];
        }
    }
    dest[strlen(src)+ strlen(str)] = '\0';
    return 1;
}

void main()
{
    char src[255] = "qweczaxn";
    const char str[255] = "wrt";
    int index = 4, len = 15;
    char dest[15];
    printf("%s\n", src);
    printf("%s\n", str);
    if (insert(src,  str, index, dest, len))
        printf("%s", dest);
    else
        printf("sorry its error");
}
