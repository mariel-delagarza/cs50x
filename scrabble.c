#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    } else if (score2 > score1) {
        printf("Player 2 wins!\n");
    } else printf("Tie\n");
}

int compute_score(string word)
{
    // initialize score counter and set to 0 to start
    int score = 0;

    // go over each character in 'word'
    for (int i = 0; i < strlen(word); i++) {
        // if that character is alphabetical (not punctuation)
        if (isalpha(word[i]))
            // tolower() takes the letter and makes it lowercase
            // since we know case is immaterial to value.
            // we know that the index in POINTS[] for a letter
            // will be that letter's ASCII value minus 'a', since
            // we want 'a' to equal 0 (where we start).
            score += POINTS[tolower(word[i]) - 'a' ];

    }

    printf("%i\n", score);

    return score;
}
