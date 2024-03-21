#include <stddef.h>
#include <stdlib.h>

size_t my_strlen(const char *s)
{
    size_t i = 0;

    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

char* my_strdup(const char *str)
{
    size_t len = my_strlen(str);
    char* newstr = (char*)malloc(len + 1);

    while (*str != '\0')
    {
        *newstr = *str;
        newstr++;
        str++;
    }
    return newstr - (len + 1);
}

int my_strcmp(const char* str1, const char* str2)
{
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

char* my_strstr(const char* str1,const char* str2)
{
	char* cur = (char*)str1;
	while (*cur != '\0')
	{
		str1 = cur;
		while((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2))
		{
			str1++;
			str2++;
		}
		if (*str2 == '\0')
		{
			return cur;
		}
		cur++;
	}
    return NULL;
}

char* my_strcat(char* d, const char* s)
{
    while (*d != '\0')
        d++;
    while (*s != '\0')
    {
        *d = *s;
        s++;
        d++;
    }
    *d = '\0';
    return d - my_strlen(d) + 1;
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