#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string text);
char rotate(char input, int key);

//argc is the argument count
//argv[] is the argument list
int main(int argc, string argv[])
{
    // must accept a single agrument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string input = get_string("plaintext: ");

    printf("ciphertext: ");

    for (int i = 0; i < strlen(input); i++)
    {
        rotate(input[i], key);
    }

    printf("\n");
    return 0;
}

bool only_digits(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }

    return true;
}

char rotate(char input, int key)
{
    // formula: c[i] = (p[i] + k)%26
    // use 'A' and 'a' to convert from
    // ASCII and back


    // 'A' = 65
    if (isupper(input))
    {
        char character = ((input - 'A') + key) % 26 + 'A';
        printf("%c", character);
        return 0;
    }

    // 'a' = 97
    if (islower(input))
    {
        char character = ((input - 'a') + key) % 26 + 'a';
        printf("%c", character);
        return 0;
    }

    else
    {
        printf("%c", input);
    }

    return 0;
}
