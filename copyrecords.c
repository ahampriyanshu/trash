#include <stdio.h>
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
