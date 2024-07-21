// This is a passion of mines, as I am also hugely into language learning, and am learning Arabic(A1), and french(A2). Currently I speak english, and tamil. People from diverse communities around the world can't practice there English due to not being in an english speaking country. This game is to practice the longest words the player remembers. This is acticve recall of vocabulary, and helps people understand words that seem odd to non-native speakers like WOW, or LOL. Some words are capitalised, and the more words you have in capital the more points you get per letter in this game.

// Coded fully in C. Credit to Aymaan Anhardeen
/ Includes all the libaries I needed to use.
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
// Defines variables before they are used inside my program of Scrabble.
int compute_score(string word);
int temp_Points[] = {};
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int small_letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
int capital_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int main(void)
{
    // Gets input from Player 1
    string Player1 = get_string("Player 1: ");
    // Gets input from player 2
    string Player2 = get_string("Player 2: ");
    // Compute score was mentioned before for this purpose. This calculates the score of each player.
    int score1 = compute_score(Player1);
    int score2 = compute_score(Player2);
    // If player 1 score is highter than player 2 than we can say player 1 wins.
    if (score1 > score2)
    {
        printf("Player 1 wins. \n");
    }
    // Else if command to see if player 2's score is higher than player 1s score.
    else if (score1 < score2)
    {
        printf("Player 2 wins. \n");
    }
    else
    // Anything else is considered a tie.
    {
        printf("Tie. \n");
    }
}
int compute_score(string word)
{
    // Score starts at 0
    int score = 0;
    // Determines lenght of the word(number of letters).
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        // Applies rules for if the word is uppercase.
        {
            for (int f = 0; f < sizeof(capital_letters); f++)
            // Calculates amount of capital letters to give the right amount of points
            {
                if (temp_Points[i] == capital_letters[f])
                {
                    temp_Points[i] = points[f];
                    score += temp_Points[i];
                    // Gives adequate points for those points that are uppercase.
                }
            }
        }
    }
    // Determines the lenth of the word.
    for (int i = 0; i < strlen(word); i++)
    if (islower(word[i]))
    // Checks if the word is lowercase or uppercase.
    {
        for (int f = 0; f < sizeof(small_letters); f++)
        // Number of lowercase letters.
        {
            if (word[i] == small_letters[f])
            {
                temp_Points[1] = points[f];
                score += temp_Points[i];
                // Gives the amount of points for lower case letters.

            }
        }
    }
    else
    {
        i += 1;
        // Doesn't give points.
    }
    return score;
    // Returns the score of the person.
}
