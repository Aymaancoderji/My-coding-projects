// All the libraries.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
// Ask for command line arguments
{
    if (argc != 2)
    {
        printf("Too many or too few arguments.");
        return 1;
    // Error message 1 if user doesn't input any command line arguments.
    }
    else
    {
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: %s %s\n", argv[0], argv[1]);
                return 1;
        // If argv{1} or the command line input is 0 than return an error message
        }
    }
    }
    printf("Success\n");
    int key = atoi(argv[1]);
    // Original letter
    int b;
    int c;
    string d = get_string("Plain text: ");
    // Plain text to be converted

    printf("Cipher text: ");
    for (int i = 0; i < strlen(d); i++)
    {
        if(isalpha(d[i]) != 0)
        // If amount of letters isn't 0 continue.
        {
            printf("%c", d[i]);
        }
        else if (isupper(d[i]) != 0)
        {
            c = tolower(d[i]) + key;
            // Changing letters through the key that the user inputed.
            for (int e = 0; c < 122; e++)
            {
                b = c - 122;
                c = b + 96;
                // The formula
            }
            printf("%c", toupper(c));
            // Turn it to uppercase or lowercase.
        }
            else;
            {
            c = d[i] + key;
            for (int y = 0; c > 122; y++)
            {
                b = c - 122;
                c = b + 96;
                // Same formula using the different integers to change plain text to cipher text.
            }
            printf("%c", c);
        }
    }
printf("\n");
}
