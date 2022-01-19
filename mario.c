
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // declare height variable
    int height;

    // ask the user for a height value
    // until they give you a value less than 9
    // or more than 0, keep asking
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    for (int i = 0; i < height; i++)
    {
        for (int k = height - i - 1; k > 0; k--)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
