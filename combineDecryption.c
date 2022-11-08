#include<stdio.h>
#include<math.h>
#include<string.h>

char message[20],message2[20],decryptedMsg1[20],x[1],y[1],z[1];
char characters[53]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'}, ciphertext[3], messagetext[3], allMessagetext[3];
int i,j,matrixKey2[3][3],k,w,matrixKey[2][2],matrixKey3[2][2];
int number[3], cipher[3];
int choice,choice2;
int determinant;
char temp;

void decryption2x2(char ch1[], char ch2[])
{
    char encrypt[3]= {};
    encrypt[2] = '\0';

    strcat(encrypt,ch1);
    strcat(encrypt,ch2);
    printf("\n-> Two-pair encrypted character text is: ");
    puts(encrypt);

    number[0]=0;
    number[1]=0;
    cipher[0]=0;
    cipher[1]=0;
    ciphertext[0] = 0;
    ciphertext[1] = 0;

    for(i=0; i<=1; i++)
    {
        for(j=0; j<=25; j++)
        {
            if( encrypt[i] == characters[j])
            {
                number[i] = j;
            }
        }
    }

    printf("Alphabetical ordered number text will be-\n");
    for(k=0; k <= 1; k++)
        printf("%d  ", number[k]);

    for(i=0; i<=1; i++)
    {
        for(j=0; j<=1; j++)
        {
            cipher[i] = cipher[i] + ( matrixKey3[i][j] * number[j] );
        }

        cipher[i] = cipher[i]%26;

        for(k=0; k<=25; k++)
        {
            if(cipher[i] == k)
                messagetext[i] = characters[k];
        }
    }

    printf("\nGenerated message text in alphabetical ordered number text will be-\n");
    for(i=0; i<=1; i++)
        printf("%d ", cipher[i]);

    printf("\n->> message text of the pair will be: ");
    // puts(messagetext);
    printf("%s <<- (Hill Message)\n", messagetext);
}
void matrixKey_inverse(int matrixKey3[2][2])
{
    printf("\nDeterminant of entered key matrix is: ");
    determinant = ( matrixKey3[1][1]*matrixKey3[0][0] ) - ( matrixKey3[0][1]*matrixKey3[1][0] ) ;
    determinant = determinant%26;
    printf("%d", determinant);

    printf("\n\nAdjoint of the entered key matrix will be- \n");
    matrixKey3[0][1] = -matrixKey3[0][1] + 26;
    matrixKey3[1][0] = -matrixKey3[1][0] + 26;
    temp = matrixKey3[0][0];
    matrixKey3[0][0] = matrixKey3[1][1];
    matrixKey3[1][1] = temp;

    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            printf("%d  ",matrixKey3[i][j]);
        }
        printf("\n");
    }

    int d;
    int x=0;
    for(x=1; x<25; x++){
        if( (x*determinant)%26 == 1)
            d = x;
    }
    printf("\n D-inverse will be: %d", d);

    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            matrixKey3[i][j] = (matrixKey3[i][j] * d)%26;
        }
    }

    printf("\nInverse of key matrix will be- \n");
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            printf("%d  ",matrixKey3[i][j]);
        }
        printf("\n");
    }
}



void main()
{
    printf("======= Dekripsi Hill, Vigenere, & Caesar Ciphers =======\n");
    printf("\nEnter the cipher text: ");
    scanf("%s", &decryptedMsg1);

    printf("\n======= 1. Hill Cipher =======\n");
    printf("Enter the 2*2 Key Matrix-");
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            scanf("%d",&matrixKey3[i][j]);
        }
    }
    printf("\nEntered Key is:\n");
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            printf("%d  ",matrixKey3[i][j]);
        }
        printf("\n");
    }

    matrixKey_inverse(matrixKey3);

    printf("\n--- Decrypting each two-character pair of plain text ---");

    for(w=0; decryptedMsg1[w] != '\0'; ){

        x[0] = decryptedMsg1[w];
        x[1] = '\0';

        y[0] = decryptedMsg1[w+1];
        y[1] = '\0';

        decryption2x2(x, y);
        w = w + 2;
    }


    printf("\n======= 2. Vigenere Cipher =======\n");
    char key2[100], ch, hillMessage[100];
    printf("Hill Message : ");
    scanf("%s", &hillMessage);
    printf("Vigenere Key (string) : ");
    scanf("%s", &key2);
    
    int msgLen = strlen(message), keyLen = strlen(key2);
    char newKey[msgLen], decryptedMsg2[msgLen];

    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
        
        newKey[i] = key2[j];
    }
 
    newKey[i] = '\0';
    
    for(i = 0; hillMessage[i] != '\0'; ++i){
        ch = hillMessage[i];
        
        if(ch >= 'a' && ch <= 'z'){
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            decryptedMsg2[i] = (((hillMessage[i] - newKey[i]) + 14) % 26) + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z'){
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            decryptedMsg2[i] = (((hillMessage[i] - newKey[i]) + 26) % 26) + 'A';
        }else{
            decryptedMsg2[i] = ch;
        }
        // printf("> %c <", hillMessage[i]);
    }
    decryptedMsg2[i] = '\0';

    printf("Hill Message: %s", message);
    printf("\nKey: %s", key2);
    printf("\nVigenere Message: %s\n", decryptedMsg2);



    int key1;
    printf("\n======= 3. Caesar Cipher =======\n");
    printf("Caesar Key (number) : ");
    scanf("%d", &key1);

    for(i = 0; decryptedMsg2[i] != '\0'; ++i){
        ch = decryptedMsg2[i];
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key1 + 5;
            
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            decryptedMsg2[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key1;
            
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            decryptedMsg2[i] = ch;
        }
    }
    printf("Caesar message: %s\n", decryptedMsg2);
    printf("So, the content file from plain text is: %s\n\n", decryptedMsg2);
}
