#include<stdio.h>
#include<string.h>
 
int main(){
    char msg[] = "THE CRAZY PROGRAMMER xyz cba ._o._ ";
    char key[] = "HELLO";
    char ch;
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
 
    //generating new key
    for(i = 0, j = 0; i < msgLen; ++i, ++j){
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 
    newKey[i] = '\0';
 
    //encryption
    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        
        if(ch >= 'a' && ch <= 'z'){
            encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z'){
            encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
        }else{
            encryptedMsg[i] = ch;
        }
    }
    encryptedMsg[i] = '\0';
 
    //decryption
    for(i = 0; msg[i] != '\0'; ++i){
        ch = msg[i];
        
        if(ch >= 'a' && ch <= 'z'){
            if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 14) % 26) + 'a';
        }
        else if(ch >= 'A' && ch <= 'Z'){
            if(ch < 'A'){
                ch = ch + 'Z' - 'A' + 1;
            }
            decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
        }else{
            decryptedMsg[i] = ch;
        }
    }
    decryptedMsg[i] = '\0';
 
    printf("Original Message: %s\n", msg);
    printf("Key: %s\n", key);
    printf("New Generated Key: %s\n", newKey);
    printf("Encrypted Message: %s\n", encryptedMsg);
    printf("Decrypted Message: %s\n", decryptedMsg);
 
    return 0;
}
// reference : 
// https://www.thecrazyprogrammer.com/2017/08/vigenere-cipher-c-c.html
