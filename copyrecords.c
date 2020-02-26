#include <stdio.h>

string encrypt(string text, int s) 
{ 
    string result = ""; 
  
    // traverse text 
    for (int i=0;i<text.length();i++) 
    { 
        // apply transformation to each character 
        // Encrypt Uppercase letters 
        if (isupper(text[i])) 
            result += char(int(text[i]+s-65)%26 +65); 
  
    // Encrypt Lowercase letters 
    else
        result += char(int(text[i]+s-97)%26 +97); 
    } 
  
    // Return the resulting string 
    return result; 
} 

int main()
{
    char ch;

    FILE *fpbr, *fpbw;

    fpbr = fopen("bin1.exe", "rb");

    /* test logic for successful open*/
    if (fpbr == NULL)
    {
        puts("Input Binary file is having issues while opening");
    }

    /* Opening file bin2.exe in “wb” mode for writing*/
    fpbw= fopen("bin2.exe", "wb");

    /* Ensure bin2.exe opened successfully*/
    if (fpbw == NULL)
    {
       puts("Output binary file is having issues while opening");
    }

    /*Read & Write Logic for binary files*/
    while(1)
    {
        ch = fgetc(fpbr);
        if (ch==EOF)
             break;
         else
             fputc(ch, fpbw);
     }

     /* Closing both the binary files */
     fclose(fpbr);
     fclose(fpbw);

     return 0;
}
