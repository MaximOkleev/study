int my_isalpha(int s)
{
    return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z');
}

int my_isdigit(int s)
{
    return '0' <= s && s <= '9';
    // return (0 <= s && s <= 9);
}

int my_isblank(int c)
{
    return c == ' ' || c == '\t';
}

int my_isalnum(int s)
{
    return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || ('0' <= s && s <= '9');
}

int my_islower(int s)
{
    return s >= 'a' && s <= 'z';
}

int my_ispunct(int s)
{
    return s == ',' || s == '.' || s == ':' || s == ';' || s == '\"' || s == '?' || s == '\'' || s == '!' || s == '#' || s == '$' || s == '%' || s == '<' || s == '>' || s == '=' ||  s == '&' || s == '(' || s == ')' || s == '*' || s == '+' || s == '-' || s == '/' || s == '@' || s == '[' || s == ']' || s == '\\' || s == '^' || s == '_' || s == '`' || s == '{' || s == '}' || s == '|' || s == '~';
}

int my_isupper(int s)
{
    return s >= 'A' && s <= 'Z';
}

int my_iscntrl(int s)
{
    return s < 32 || s == 127;
}

int my_isxdigit(int s)
{
    return 48 <= s && s <= 57 || 65 <= s && s <= 70 || 97 <= s && s <= 102;
}

int my_isgraph(int s)
{
    return s >= 33 && s < 127;
}

int my_isprint(int s)
{
    return s >= 32 && s < 127;
}

int my_isspace(int s)
{
    return s == ' ' || s == '\n' || s == '\t' || s == '\v' || s == '\f' || s == '\r';
}


#ifdef MAIN

#include <stdio.h>
#include <ctype.h>
#include <assert.h>

int main()
{
    int (*lib_foo)(int) = isspace;
    int (*my_foo)(int) = my_isspace;

    for (int i = 0; i < 256; i++)
    {
        if ((my_foo(i) == 0) ^ (lib_foo(i) == 0))
        {
            printf("%d, %d - %d\n", i, my_foo(i) == 0, lib_foo(i) == 0);
            // puts("FAILED");
        }
    }
}

#endif
