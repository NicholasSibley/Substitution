#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Program to encrypt messages using a substituion cipher
// Key should be 26 alphabetic characters where each character replaces it's given position
// For example: a key of ZYXWVUTSRQPONMLKJIHGFEDCBA would simply reverse the alphabet
int main(int argc, string argv[])
{

    // Output if an incorrect number of command-line arguments are used
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Output if the key is not a letter
    string key = argv[1];
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must be a letter.\n");
            return 1;
        }
    }

    // Output if the key is not 26 characters in length
    if (strlen(key) != 26)
    {
        printf("Key must be 26 characters.\n");
        return 1;
    }

    //Output if the key contains duplicate letters
    for (int j = 0; j < strlen(key); j++)
    {
        for (int k = j + 1; k < strlen(key); k++)
        {
            if (toupper(key[j]) == toupper(key[k]))
            {
                printf("Key must not include duplicate letters.\n");
                return 1;
            }
        }
    }

    // Prompt the user for plaintext
    string plaintext = get_string("What is your plaintext?\n");

    // Convert all lowercase letters to uppercase
    for (int L = 0; L < strlen(key); L++)
    {
        if (islower(key[L]))
        {
            key[L] = key[L] - 32;
        }
    }

    printf("ciphertext: ");

    // Encrypt the text and print the result
    for (int m = 0; m < strlen(plaintext); m++)
    {
        if (isupper(plaintext[m]))
        {
            int letter = plaintext[m] - 65;
            printf("%c", key[letter]);
        }

        else if (islower(plaintext[m]))
        {
            int letter = plaintext[m] - 97;
            printf("%c", key[letter] + 32);
        }

        else
            printf("%c", plaintext[m]);
    }
    printf("\n");
}
