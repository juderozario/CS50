#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main (int argc, string argv[])
{
    if (argc != 2) // Check existence of a KEY
    {
        printf("Usage ./substitution KEY\n");
        return 1;
    }
    if (strlen(argv[1]) != 26) // Check if the key is 26 characters
    {
        printf("Key must be 26 characters\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++) // Iterate through the KEY to check if there is a invalid character
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Use alphabets only as a key\n");
            return 1;
        }
    }
    string key = argv[1]; // Setting the KEY stored in a variable called key
    for (int i = 0; i < strlen(key); i++) // Check setting all the KEY characters to UPPERCASE
    {
        key[i] = toupper(key[i]);
    }
    for (int i = 0; i < strlen(key); i++) // Check if there is a duplicate in the key
    {
        char duplicate = key[i];
        if (strchr(key + 1 + i , duplicate))
        {
            printf("No duplicate characters\n");
            return 1;
        }
    }
    string plaintext = get_string("Plaintext: "); // Ask for a input
    printf("ciphertext: ");
    // Temp values for the substitution process
    int temp1;
    int temp2;
    int pos;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isalpha(plaintext[i]))
        {
            if (isupper(plaintext[i])) // If the character is uppercase
            {
                temp1 = plaintext[i]; // Set the temp storage to the ASCII value of the character
                temp2 = temp1 - 'A'; // Subtracting the 'A' or 65 from the ASCII int always gives the position
                pos = temp2; // This step can be left out but just change the key[pos] to key[temp2]
                plaintext[i] = key[pos]; // Substitute the plaintext to the KEY in the position of the char
            }
            else if (islower(plaintext[i])) // Same process but turns into lower case
            {
                temp1 = plaintext[i];
                temp2 = temp1 - 'a'; // Subtracting 97 from the lowercase character to find position
                pos = temp2; // This step can be left out but just change the key[pos] to key[temp2]
                plaintext[i] = tolower(key[pos]);
            }
            printf("%c", plaintext[i]);
        }
        else
        {
            printf("%c", plaintext[i]); // No changes for characters that are not alphabets
        }
    }
    printf("\n");
    return 0;
}
