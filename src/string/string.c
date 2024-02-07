#include <stddef.h>
#include <stdlib.h>

// * []
// +- k
// ptr2 - ptr1

size_t my_strlen(const char *s)
{
    size_t i = 0; // *s

    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int my_strcmp(const char*str1, const char*str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;
}

char* my_strstr(const char* p1,const char* p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	char* s1 = p1;
	char* s2 = p2;
	char* cur =(char*) p1;
	if (*p2 == '\0')
	{
		return p1;
	}
	while (*cur)
	{
		s1 = cur;
		s2 = p2;
		while((*s1!='\0') && (*s2!='\0') && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}

char* my_strcat(char* d, const char* s)
{
    char* ptr = d + my_strlen(d);
    while (*s != '\0') {
        *ptr++ = *s++;
    }
    *ptr = '\0';
    return d;
}

char* del_elem(char array[], size_t index, size_t arr_size)
{
    for (size_t i = index; i < arr_size - 1; i++)
    {
        array[i] = array[i + 1];
    }
    char *array2 = (char*)malloc((arr_size - 1) * sizeof(char));
    for (int i = 0; i < arr_size - 1; i++)
    {
        array2[i] = array[i];
    }
    array = (char*)realloc(array2, (arr_size - 1) * sizeof(char));
    return array;
}

char* copy_array(const char* array, size_t arr_size)
{
    char *array_copy = (char*)malloc(arr_size * sizeof(char));
    
    if (!array_copy)
        return NULL;
    for (size_t i = 0; i < arr_size; i++)
        array_copy[i] = array[i];
    return array_copy;
}

char* my_strdup(const char *str)
{
    size_t str_size = my_strlen(str) + 1;
    char *str_copy = (char*)malloc(str_size * sizeof(char));
    
    if (!str_copy)
        return NULL;
    for (size_t i = 0; i < str_size; i++)
        str_copy[i] = str[i];
    return str_copy;
}

int palindrom(const char *s)
{
    const size_t len = my_strlen(s);
    int otv = 1;

    for (int i = 0; i <= len / 2; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            otv = 0;
            break;
        }
    }
    return otv;
}

// char* my_strdup(const char *s)
// my_strcat()
// my_strcpy()
// my_strstr()
// my_strcmp()


#include <stdio.h>

int main()
{
    char s[] = "abcdefg";
    char *c = del_elem(s, 2, 8);

    // char c[] = "abcd\0"; // "hello world" \0

    s[2] = 'k';
    printf("%s\n", c);
    printf("%s\n", s);
    

    return 0;
}
