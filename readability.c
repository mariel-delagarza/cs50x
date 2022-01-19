#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

  string text = get_string("Text: ");

  int letters = count_letters(text);
  int words = count_words(text);
  int sentences = count_sentences(text);

  // letters needs to be cast to a float
  // otherwise you'll get an int from
  // letters/words. same with sentences.
  float L = (float)letters / words * 100.00;
  float S = (float)sentences / words * 100.00;

  int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    printf("Grade %i\n", index);

    return 0;
}

int count_letters(string text)
{
    int count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        count++;
    }

    return count;
}

int count_words(string text)
{
  int count = 1;

  for (int i = 0; i < strlen(text); i++)
  {
    if (isspace(text[i]))
      count++;
  }

  return count;
}

int count_sentences(string text)
{
  int count = 0;

  for (int i = 0; i < strlen(text); i++)
  {
    if (text[i] == 33 || text[i] == 46 || text[i] == 63)
      count++;
  }

  return count;
}
