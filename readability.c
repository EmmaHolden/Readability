#include <cs50.h>
#include <stdio.h>
#include <wctype.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    // These are the functions I will be using
    int count_letters(string text);
    int count_words(string text);
    int count_sentences(string text);

    // Get the text from the user
    string text = get_string("Text: ");

    // Call the function to find total letters
    int letters = count_letters(text);

    // Call the function to find total words
    int words = count_words(text);

    // Call the function to find total sentences
    int sentences = count_sentences(text);

    // Find average letters per 100 words of the text (total letters divided by total words times by 100)
    float average_letters = ((float) letters / (float) words) * 100;

    // Find average sentences per 100 words of the text (total sentences divided by total words times by 100)
    float average_sentences = ((float) sentences / (float) words) * 100;

    // PLug the numbers into the formula - index = 0.0588 * L - 0.296 * S - 15.8
    float index = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }

}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (iswalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words += 1;
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((int) text[i] == 33 || (int) text[i]  == 63 || (int) text[i] == 46)
        {
            sentences += 1;
        }
    }
    return sentences;
}