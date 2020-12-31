#include <stdio.h>
#include <string.h>

#include "txtfind.h"
int substring(char *str1, char *str2)
{

    int i = 0;
    int place;
    for (int j = 0; j < strlen(str1); j++)
    {
        if (*(str2 + i) == *(str1 + j))
        {

            place = j;
            while ((*(str2 + i) == *(str1 + j)) && (i < strlen(str2)) && (j < strlen(str1)))
            {
                j++;
                i++;
            }
            if (i == strlen(str2))
            {
                return 1;
            }
            j = place;
            i = 0;
        }
    }
    return 0;
}
int similar(char *s, char *t, int n)
{
    if (n == 0)
    {
        if (strcmp(s, t) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int sLen = strlen(s);
    int tLen = strlen(t);
    if (((tLen + n) < sLen))
    {
        return 0;
    }
    int k = 0;
    int count = 0;
    for (int i = 0; i < sLen; i++)
    {
        if (*(s + i) != *(t + k))
        {
            count++;
        }
        else
        {
            if ((k != tLen))
            {
                k++;
            }
        }
    }

    if ((count == n))
    {
        return 1;
    }
    return 0;
}
void print_lines(char *str)
{
    char x;
    char line[LINE];
    int i = 0;
    while ((x = getc(stdin)) != EOF)
    {
        if (i < LINE)
            line[i] = x;
        else
        {
            printf("Line length is too large");
        }
        if (line[i] == '\n')
        {
            if (substring(line, str))
                printf("%s", line);
            line[i] = '\0';
            i = -1;
        }
        i++;
    }
}
void print_similar_words(char *str)
{
    char x;
    char word[WORD];
    int i = 0;
    while ((x = getc(stdin)) != EOF)
    {
        if (i < WORD)
            word[i] = x;
        else
        {
            printf("Word length is too large");
        }
        if (word[i] == '\n' || word[i] == '\t' || word[i] == ' ')
        {
            word[i] = '\0';
            if (similar(word, str, 1))
                printf("%s \n", word);
            i = -1;
        }
        i++;
    }
}
