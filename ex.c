#include <stdio.h> 
#include <string.h> 
#include <ctype.h>


int main ( int argc, char *argv[] )
{
	int stdin_mode,stdout_mode,com_file,reversify;

    char ch;
    char shift;

    char buffer[1500]; 
    /*Char array to store string */
    char str[24];

    /* Pointers for both binary files*/
    FILE *fpbr, *fpbw;

  if (argc == 1)  // create pin
    {
    	stdin_mode=1;
    	stdout_mode=1;
    	com_file=0;
    	reversify=0;
      }

    /* Open for bin1.exe file in rb mode */
    fpbr = fopen("myfile.txt", "rb");

    /* test logic for successful open*/
    if (fpbr == NULL)
    {
        puts("Input Binary file is having issues while opening terminating the program !");
      
    }
    
   // char //check = "-F";

    int count = fread( &buffer, sizeof(char),1500,fpbr) ;

    for (int i=1; i< argc; i++) {
      	
{
    printf("\n%s", argv[i+0]);
        }
        { /* printf("Gaand lagi hui hai"); */
        }
 }

    /* Opening file bin2.exe in “wb” mode for writing*/
    fpbw= fopen(argv[1], "wb");

    /* Ensure bin2.exe opened successfully*/
    if (fpbw == NULL)
    {
       puts("Output binary file is having issues while opening terminating the program !");
    }
    else{
             /* decode(str, shift); */
             fputs(buffer, fpbw);
         }
     /* Closing both the binary files */
     fclose(fpbr);
     fclose(fpbw);

     return 0;
}