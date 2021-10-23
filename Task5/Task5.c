#include <stdio.h>

int strlen(const char* str)
{
    int i = 0;
    while (str[i]) i++;
    return i;
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

void main()
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
