int my_isalpha(int s)
{
    return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z');
}

int my_isdigit(int s)
{
    return ('0' <= s && s <= '9');
    // return (0 <= s && s <= 9);
}

int my_isblank(int c)
{
    return (c == ' ' || c == '\n');
}

int my_isalnum(int s)
{
    return ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || ('0' <= s && s <= '9'));
}

int my_islower(int s)
{
    return (s >= 'a' && s <= 'z');
}

int my_ispunct(int s)
{
    return ((s == ',') || (s == '.') || (s == ':') || (s == ';') || (s == '\"') || (s == '?') || (s == '\''));
}

int my_isupper(int s)
{
    return(s >= 'A' && s <= 'Z');
}

/*int my_isxdigit(int s)
{

}

int my_iscntrl(int s)
{

}

int my_isgraph(int s)
{

}

int my_isprint(int s)
{

}*/

int my_isspace(int s)
{
    return(s == ' ');
}

#ifdef MAIN

#include <stdio.h>

int main()
{
    int n;

    scanf("%lc", &n);
    printf("%d", my_ispunct(n));
}

#endif
