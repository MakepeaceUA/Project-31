#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;


void Func(FILE* File, int key)
{
    FILE* Cipher = fopen("cipher.txt", "w");
    char c;

    while ((c = fgetc(File)) != EOF)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c = (c - 'A' + key) % 26 + 'A';
        }
        else if (c >= 'a' && c <= 'z')
        {
            c = (c - 'a' + key) % 26 + 'a';
        }
        fputc(c, Cipher);
    }
        fclose(Cipher);
}
       

int main()
{
    setlocale(0, "RU");
    int key = 3;

    FILE* MyFile = fopen("text.txt", "w");
    fprintf(MyFile, "Eat some more of these soft French rolls and drink some tea");
    fclose(MyFile);
    MyFile = fopen("text.txt", "r");
    
    Func(MyFile, key);
    fclose(MyFile);
}
