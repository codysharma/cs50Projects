//Takes string as input and outputs the corresponding score the word would recieve in Scrabble, without any placement bonuses

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
    //string word1 = "aa";
    //string word2 = "b";

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    //printf("%d\n", score1);
    //printf("%d\n", score2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("With a score of %d, Player 1 Wins!\n", score1);
    }
    else
    {
        if (score1 < score2)
        {
            printf("With a score of %d, Player 2 Wins!\n", score2);
        }
        else
        {
            printf("We have a tie at %d!\n", score1);
        }
    }
}

int compute_score(string word)
{
    int point = 0;
    // TODO: Compute and return score for string
    for (int i=0, n = strlen(word); i < n; i++)//go through each character in the word
    {
        //printf("check character: %c\n", word[i]);
        if (word[i] == 'a' || word[i] == 'A')//if a, search array POINTS for spot [0] and add value to "point".
        {
            //printf("for letter a: %c\n", word[i]);
            point = point + POINTS[0];
        }
        if (word[i] == 'b' || word[i] == 'B')//if b, search array POINTS for spot [1] and add value to "point".
        {
            point = point + POINTS[1];
        }
        if (word[i] == 'c' || word[i] == 'C')
        {
            point = point + POINTS[2];
        }
        if (word[i] == 'd' || word[i] == 'D')
        {
            point = point + POINTS[3];
        }
        if (word[i] == 'e' || word[i] == 'E')
        {
            point = point + POINTS[4];
        }
        if (word[i] == 'f' || word[i] == 'F')
        {
            point = point + POINTS[5];
        }
        if (word[i] == 'g' || word[i] == 'G')
        {
            point = point + POINTS[6];
        }
        if (word[i] == 'h' || word[i] == 'H')
        {
            point = point + POINTS[7];
        }
        if (word[i] == 'i' || word[i] == 'I')
        {
            point = point + POINTS[8];
        }
        if (word[i] == 'j' || word[i] == 'J')
        {
            point = point + POINTS[9];
        }
        if (word[i] == 'k' || word[i] == 'K')
        {
            point = point + POINTS[10];
        }
        if (word[i] == 'l' || word[i] == 'L')
        {
            point = point + POINTS[11];
        }
        if (word[i] == 'm' || word[i] == 'M')
        {
            point = point + POINTS[12];
        }
        if (word[i] == 'n' || word[i] == 'N')
        {
            point = point + POINTS[13];
        }
        if (word[i] == 'o' || word[i] == 'O')
        {
            point = point + POINTS[14];
        }
        if (word[i] == 'p' || word[i] == 'P')
        {
            point = point + POINTS[15];
        }
        if (word[i] == 'q' || word[i] == 'Q')
        {
            point = point + POINTS[16];
        }
        if (word[i] == 'r' || word[i] == 'R')
        {
            point = point + POINTS[17];
        }
        if (word[i] == 's' || word[i] == 'S')
        {
            point = point + POINTS[18];
        }
        if (word[i] == 't' || word[i] == 'T')
        {
            point = point + POINTS[19];
        }
        if (word[i] == 'u' || word[i] == 'U')
        {
            point = point + POINTS[20];
        }
        if (word[i] == 'v' || word[i] == 'V')
        {
            point = point + POINTS[21];
        }
        if (word[i] == 'w' || word[i] == 'W')
        {
            point = point + POINTS[22];
        }
        if (word[i] == 'x' || word[i] == 'X')
        {
            point = point + POINTS[23];
        }
        if (word[i] == 'y' || word[i] == 'Y')
        {
            point = point + POINTS[24];
        }
        if (word[i] == 'z' || word[i] == 'Z')
        {
            point = point + POINTS[25];
        }
    }
    return point;
}
