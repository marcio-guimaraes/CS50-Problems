#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);
bool has_repeated_chars(string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Valida a chave
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(plaintext); i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            int index = toupper(c) - 'A';
            char subst = key[index];

            if (isupper(c))
                printf("%c", toupper(subst));
            else
                printf("%c", tolower(subst));
        }
        else
        {
            printf("%c", c);
        }
    }

    printf("\n");
    return 0;
}

bool is_valid_key(string key)
{
    if (strlen(key) != 26)
        return false;

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
            return false;
    }

    if (has_repeated_chars(key))
        return false;

    return true;
}

bool has_repeated_chars(string key)
{
    bool letters[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        int idx = toupper(key[i]) - 'A';
        if (letters[idx])
            return true;
        letters[idx] = true;
    }

    return false;
}
