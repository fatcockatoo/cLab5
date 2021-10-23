#include <stdio.h>

char *find(const char* str, const char *substr)
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

void main()
{
    const char str[255] = "ytbjyjjtghgfjhfjygfjghj", substr[255] = "hfjygf";
    char *res = find(&str, &substr);
    printf("%d", res);
}
