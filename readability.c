#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Text: ");
    int num_letters = 0;
    //initialize words to 1 so that the loop later on counts words based on the number of spaces in a sentence.
    int num_words = 1;
    int num_sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
       //if the text reads alphabetic characters, number of letters increases
       if (isalpha(text[i]))
       {
           num_letters++;
       }
       //if the text is followed by a space, the number of words increases
       else if (text[i] == ' ' && text[i + 1] != ' ')
       {
           num_words++;
       }
       //if the text reads a '.' '!' or '?' the sentences increases
       else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
       {
           num_sentences++;
       }
    }
    //use casting to change int to float
    float L = (100 * (float) num_letters / (float) num_words);
    float S = (100 * (float) num_sentences / (float) num_words);
    float grade = 0.0588 * L - 0.296 * S - 15.8;
    if (grade < 16 && grade >= 0)
    {
        //use casting to change the float grade to an int
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}