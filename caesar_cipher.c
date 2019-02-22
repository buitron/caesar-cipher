# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <math.h>

# define MAX_PLAIN_SZ 256

char cipher(char p, int k);
int main(int argc, char *argv[])
{   
    char *key = argv[1];
    
    // validate if script arguments
    if (argc > 2 || argc < 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    
    for (int i = 0; i < strlen(key); i++)
    {
        if (!isdigit(key[i]))
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }
    
    // enter main cipher function
    int k = 0, counter = 0;
    for (int i=0, len=strlen(key); i < len; len--)
    {
        k += (key[(len-1)] - '0') * pow(10, counter);
        counter++;
    }

    char *plain = malloc(MAX_PLAIN_SZ);
    printf("plaintext:  ");
    fgets(plain, MAX_PLAIN_SZ, stdin);
    
    
    char ci[strlen(plain)];
    for (int i=0; i < strlen(plain); i++)
    {
        if(isalpha(plain[i]))
        {
            ci[i] = cipher(plain[i], k);
        }
        else
        {
            ci[i] = plain[i];
        }
    }    
    ci[strlen(plain) - 1] = '\0';
    printf("ciphertext: %s\n", ci);
    
    free(plain);
    return 0;
}

char cipher(char p, int k)
{
    if (p >= 97)
    {
        p = p - 97;
        return ((p + k) % 26) + 97;
    }
    else
    {
        p = p - 65;
        return ((p + k) % 26) + 65;
    }
}

