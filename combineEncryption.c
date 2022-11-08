#include<stdio.h>
#include<math.h>
#include<string.h>

char message[20],message2[20],encrypted[20],x[1],y[1],z[1];
char characters[53]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'}, ciphertext[3], messagetext[3];
int i,j,matrixKey2[3][3],k,w,matrixKey[2][2],matrixKey3[2][2];
int number[3], cipher[3];
int choice,choice2;
int determinant;
char temp;

void encryption2x2(char ch1[], char ch2[])
{
    char encryptedMsg3[3]= {};
    encryptedMsg3[2] = '\0';

    strcat(encryptedMsg3, ch1);
    strcat(encryptedMsg3, ch2);
    printf("\n-> Two-pair character text is: ");
    puts(encryptedMsg3);

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
            if( encryptedMsg3[i] == characters[j])
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
            cipher[i] = cipher[i] + ( matrixKey[i][j] * number[j] );
        }

        cipher[i] = cipher[i]%26;

        for(k=0; k<=25; k++)
        {
            if(cipher[i] == k)
                ciphertext[i] = characters[k];
        }
    }

    printf("\nGenerated Cipher text in alphabetical ordered number text will be-\n");
    for(i=0; i<=1; i++)
        printf("%d ", cipher[i]);

    printf("\n->> Cipher text of the pair will be: ");
    puts(ciphertext);
}



void main()
{
    FILE *fp; // declaration of file pointer
    // char message[1000], ch; // variable to read the content
    char ch;
    fp = fopen("input_message.txt", "r"); // opening of file
    // if (!fp) return 1; // checking for error
    
    while (fgets(message, 1000, fp) != NULL) // reading file content
    printf("======= Enkripsi Plain Text ke Caesar, Vigenere, & Hill Ciphers =======\n");
    printf("Plain Text: %s\n\n", message);
    fclose(fp); // closing file

    int key1;
    printf("======= 1. Caesar Cipher =======\n");
    printf("Caesar Key (number) : ");
    scanf("%d", &key1);

    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key1;
            
            if(ch > 'z'){
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key1;
            
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    printf("Encrypted Message-1: %s\n", message);



    printf("\n======= 2. Vigenere Cipher =======\n");
    char key2[100];
    printf("Vigenere Key (string) : ");
    scanf("%s", &key2);
    
    int msgLen = strlen(message), keyLen = strlen(key2);
    char newKey[msgLen], encryptedMsg2[msgLen], decryptedMsg[msgLen];
    
    //if the key is lowercase
    for(i = 0; i < keyLen; ++i){
        if(key2[i] >= 'a' && key2[i] <= 'z'){
            key2[i] = key2[i] - 32;
        }
    }

    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
        
        newKey[i] = key2[j];
    }
 
    newKey[i] = '\0';
 
    //encryption
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        
        if(ch >= 'a' && ch <= 'z'){
            encryptedMsg2[i] = ((message[i] + newKey[i]) % 26) + 'a';
        }else if(ch >= 'A' && ch <= 'Z'){
            encryptedMsg2[i] = ((message[i] + newKey[i]) % 26) + 'A';
        }else{
            encryptedMsg2[i] = ch;
        }
    }
    encryptedMsg2[i] = '\0';
    printf("Original Message: %s", message);
    printf("\nKey: %s", key2);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message-2: %s\n", encryptedMsg2);


    printf("\n======= 3. Hill Cipher =======\n");
    printf("Enter the 2*2 key Matrix-");
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            scanf("%d", &matrixKey[i][j]);
        }
    }
    printf("\nmatrixKey is:\n");
    for(i=0;i<=1;i++)
    {
        for(j=0;j<=1;j++)
        {
            printf("%d  ", matrixKey[i][j]);
        }
        printf("\n");
    }
    printf("\n--- Encrypting each two-character pair of message text ---");

    for(w=0; encryptedMsg2[w] != '\0'; ){

        x[0] = encryptedMsg2[w];
        x[1] = '\0';

        y[0] = encryptedMsg2[w+1];
        y[1] = '\0';

        encryption2x2(x, y);
        w = w + 2;
    }
}
