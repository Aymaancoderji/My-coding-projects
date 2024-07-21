#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
// As many learners of english have to do reading practice, this tool gives them the option to see how complex the text they want to read is. I have a passion for language learning, and thought this would be a good way to put that into practice. Simpler texts can be for beginners in the english language, and "grade 16" can be for more advanced learners. Overall this tool is effective in giviing instant information on how readable a text is for learners of english, and anyone else.
int main(void)
{
   // Get input from user.
    string text = get_string("Text: ");
    // I is equivilent to the number of letters in the text given by the user
    int i = strlen(text);
    // Standardises all the letters to 0.
    int letters = 0;
    int words = 0;
    int sentences = 0;
    // Counting up the characters under this line.
    for (int j = 0; j < i; j++)
    {
         char c = text[j];
         //This makes sure the input was in the English alphebet. If so it than adds the letters to the variable letters
         if (isalpha(c) != 0)
         {
            letters++;
         }
         if (c == ' ')
         // Determines the amount of words based on the space bar.
         {
            words++;
         }
         if (c == '!' || c == '.'|| c == '?')
         // These are 3 ways to end a sentance, a user may use any. This function cacluates the number of sentances in the code.
         {
            sentences++;
         }
    }
words = words + 1;
// The last word in a sentance doesn't have the " " but rather something like ".", "?" or "!", to equate for that we add 1 to the amount of words there are.
float L = ((float) letters / (float) words)*100;
// Takes an average of how long a word is on average.
float S = ((float) words / (float) sentences)*100;
// Takes an average of how many words are in a sentance on average.
float subindex = 0.0588 * L - 0.296 * S - 15.8;
// Credit to Coleman-Liau index for the readability calculator
int index = round(subindex);
// Rounds the value
if (index > 16)
{
   printf("grade 16. \n");
   // Anything above 16 is considered grade 16.
}
else if (index < 1)
{
   printf("Before grade 1. \n");
   // Anything below 1 is considered before grade 1.
}
else
{
   printf("grade %i\n", index);
   // If the number is over 1, and lower than 16 we just let them know the grade the reading is.
}
}
