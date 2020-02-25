#include <stdio.h>
int main( int argc, const char** argv)
{
    char ch;
    /*Char array to store string */
    char str[24];

    /* Pointers for both binary files*/
    FILE *fpbr, *fpbw;

    /* Open for bin1.exe file in rb mode */
    fpbr = fopen("myfile.txt", "rb");

    /* test logic for successful open*/
    if (fpbr == NULL)
    {
        puts("Input Binary file is having issues while opening going to stdin mode");
      
    }

     while(1)
    {
       if(fgets(str, 24, fpbr) ==NULL)
            break;
    }


    /* Opening file bin2.exe in “wb” mode for writing*/
    fpbw= fopen("decodedfile.txt", "wb");

    /* Ensure bin2.exe opened successfully*/
    if (fpbw == NULL)
    {
       puts("Output binary file is having issues while opening going to stdout mode");
    }

             fputs(str, fpbw);

     /* Closing both the binary files */
     fclose(fpbr);
     fclose(fpbw);

     return 0;
 }