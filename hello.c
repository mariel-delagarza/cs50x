#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Ask user for name, save as "name"
    string name = get_string("What's your name? ");

    //Interpolate "name" and print
    printf("hello, %s\n", name);
}
