#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words (string text);
int count_sentences (string text);

int main(void)
{
    string text = get_string("Text: ");
    //printf("%s\n", text);
    int length = count_letters(text);
    //printf("Length: %i letters\n", length);
    int words = count_words(text);
    //printf("Words: %i\n", words);
    int sent = count_sentences(text);
    //printf("Sentences: %i\n", sent);

    float index = 0;
    index = (float)length / words * 100 * .0588 - (float)sent / words * 100 * .296 - 15.8;
    index = round(index);
    //printf("index1: %f\n", index);

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
        {
            if (index < 1)
            {
                printf("Before Grade 1\n");
            }
            else
            {
                printf("Grade %i\n", (int)index);
            }
    }
}

int count_letters(string text)
{
    int length = strlen(text);
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) == 0)//if the character is not an alphabet, then subract 1 from the variable "length"
        (
            length = length - 1
        );
    }
    return length;
}

int count_words(string text)
{
    int words = 1;
    //if space is detected while going through each character in the array "text", add one to variable "words".
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

     return words;
}

int count_sentences(string text)
{
    int sent = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text [i] == '!' || text[i] == '?')
        {
            sent++;
        }
    }
    return sent;
}