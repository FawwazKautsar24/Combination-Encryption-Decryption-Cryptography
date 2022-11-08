#include <stdio.h>
#include <math.h>
#include <string.h>

char plain[20], plain2[20], encrypted[20], x[1], y[1], z[1];
char characters[53] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'}, ciphertext[3], plaintext[3];
int i, j, key2[3][3], k, w, key[2][2], key3[2][2];
int number[3], cipher[3];
int choice, choice2;
int determinant;
char temp;

void encryption2x2(char ch1[], char ch2[])
{
    char plain[3]= {};
    plain[2] = '\0';

    strcat(plain,ch1);
    strcat(plain,ch2);
    printf("\n->Two-pair character text is: ");
    puts(plain);

    number[0] = 0;
    number[1] = 0;
    cipher[0] = 0;
    cipher[1] = 0;
    ciphertext[0] = 0;
    ciphertext[1] = 0;

    for(i = 0 ; i <= 1 ; i++)
    {
        for(j = 0 ; j <= 25; j++)
        {
            if( plain[i] == characters[j])
            {
                number[i] = j;
            }
        }
    }

    printf("Alphabetical ordered number text will be-\n");
    for(k = 0; k <= 1; k++)
        printf("%d  ", number[k]);

    for(i = 0; i <= 1; i++)
    {
        for(j = 0; j <= 1; j++)
        {
            cipher[i] = cipher[i] + ( key[i][j] * number[j] );
        }

        cipher[i] = cipher[i]%26;

        for(k = 0; k <= 25; k++)
        {
            if(cipher[i] == k)
                ciphertext[i] = characters[k];
        }
    }

    printf("\nGenerated Cipher text in alphabetical ordered number text will be-\n");
    for(i = 0; i <= 1; i++)
        printf("%d ", cipher[i]);

    printf("\n->>Cipher text of the pair will be: ");
    puts(ciphertext);
}

void key_inverse(int key3[2][2])
{
    printf("\nDeterminant of entered key matrix is: ");
    determinant = ( key3[1][1]*key3[0][0] ) - ( key3[0][1]*key3[1][0] ) ;
    determinant = determinant%26;
    printf("%d", determinant);

    printf("\n\nAdjoint of the entered key matrix will be- \n");
    key3[0][1] = -key3[0][1] + 26;
    key3[1][0] = -key3[1][0] + 26;
    temp = key3[0][0];
    key3[0][0] = key3[1][1];
    key3[1][1] = temp;

    for(i = 0; i <= 1; i++)
    {
        for(j = 0; j <= 1; j++)
        {
            printf("%d  ",key3[i][j]);
        }
        printf("\n");
    }

    int d;
    int x = 0;
    for(x = 1; x < 25; x++){
        if( (x*determinant) % 26 == 1)
            d = x;
    }
    printf("\nD-inverse will be: %d", d);

    for(i = 0; i <= 1; i++)
    {
        for(j = 0; j <= 1; j++)
        {
            key3[i][j] = (key3[i][j] * d) % 26;
        }
    }

    printf("\nInverse of Key matrix will be- \n");
    for(i = 0;i <= 1;i++)
    {
        for(j = 0;j <= 1;j++)
        {
            printf("%d  ",key3[i][j]);
        }
        printf("\n");
    }
}

void decryption2x2(char ch1[], char ch2[])
{
    char encrypt[3]= {};
    encrypt[2] = '\0';

    strcat(encrypt,ch1);
    strcat(encrypt,ch2);
    printf("->Two-pair encrypted character text is: ");
    puts(encrypt);

    number[0] = 0;
    number[1] = 0;
    cipher[0] = 0;
    cipher[1] = 0;
    ciphertext[0] = 0;
    ciphertext[1] = 0;

    for(i = 0; i <= 1; i++)
    {
        for(j = 0; j <= 25; j++)
        {
            if( encrypt[i] == characters[j])
            {
                number[i] = j;
            }
        }
    }

    printf("Alphabetical ordered number text will be-\n");
    for(k = 0; k <=  1; k++)
        printf("%d  ", number[k]);

    for(i = 0; i <= 1; i++)
    {
        for(j = 0; j <= 1; j++)
        {
            cipher[i] = cipher[i] + ( key3[i][j] * number[j] );
        }

        cipher[i] = cipher[i] % 26;

        for(k = 0; k <= 25; k++)
        {
            if(cipher[i] == k)
                plaintext[i] = characters[k];
        }
    }

    printf("\nGenerated Plain text in alphabetical ordered number text will be-\n");
    for(i = 0; i <= 1; i++)
        printf("%d ", cipher[i]);

    printf("\n->>Plain text of the pair will be: ");
    puts(plaintext);
    printf("\n");
}



void main()
{
    printf("Hill Cipher");
    printf("\n--------2x2 Hill Cipher-----------");
    printf("\n1. Encryption\t2. Decryption\t3. EXIT");
    printf("\nEnter your choice:");
    scanf("%d", &choice);
    switch(choice)
    {
                    case 1: do{
                        printf("\nEnter the plain text: ");
                        scanf("%s", &plain);

                        printf("\nEnter the 2*2 Key Matrix-");
                        for(i = 0; i <= 1; i++)
                        {
                            for(j = 0; j <= 1; j++)
                            {
                                scanf("%d",&key[i][j]);
                            }
                        }
                        printf("\nKey is:\n");
                        for(i = 0; i <= 1; i++)
                        {
                            for(j = 0; j <= 1; j++)
                            {
                                printf("%d  ",key[i][j]);
                            }
                            printf("\n");
                        }
                        printf("\n--- Encrypting each two-character pair of plain text ---");

                        for(w = 0; plain[w] != '\0'; ){

                            x[0] = plain[w];
                            x[1] = '\0';

                            y[0] = plain[w + 1];
                            y[1] = '\0';

                            encryption2x2(x, y);
                            w = w + 2;
                        }
                        break;

                    case 2: printf("\nEnter the cipher text: ");
                        scanf("%s", &encrypted);

                        printf("\nEnter the 2*2 Key Matrix-");
                        for(i = 0; i <= 1; i++)
                        {
                            for(j = 0; j <= 1; j++)
                            {
                                scanf("%d",&key3[i][j]);
                            }
                        }
                        printf("\nEntered Key is:\n");
                        for(i = 0; i <= 1; i++)
                        {
                            for(j = 0; j <= 1; j++)
                            {
                                printf("%d  ",key3[i][j]);
                            }
                            printf("\n");
                        }

                        key_inverse(key3);

                        printf("\n-------------------Decrypting each two-character pair of plain text-----------------------\n\n");

                        for(w = 0; encrypted[w] != '\0'; ){

                            x[0] = encrypted[w];
                            x[1] = '\0';

                            y[0] = encrypted[w + 1];
                            y[1] = '\0';

                            decryption2x2(x, y);
                            w = w + 2;
                        }
                        break;

        }while(choice != 3);
    }
}
// reference : 
// https://github.com/swapnilchokshi/Hill-Cipher
