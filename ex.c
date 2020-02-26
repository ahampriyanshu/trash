#include <stdio.h> 
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>


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

    // Reading file in binary mode
  
     for (int i=1; i< argc; i++) 
    {
      if (0 == strcmp(argv[i], "-F"))
       {

       fpbr = fopen(argv[i+1], "rb");
    if (fpbr == NULL)
    {
        puts("Input Binary file is having issues while opening terminating the program !");
        exit(1);
      
    }
    int count = fread( &buffer, sizeof(char),1500,fpbr) ;
      break;

    } else {
      
     gets(buffer);
}	
    
    /*now producing the output  file */

    for (int i=1; i< argc; i++) 
    {
      if (0 == strcmp(argv[i], "-O"))
       {

      fpbw= fopen(argv[i+1], "wb");
      fputs(buffer, fpbw);
          if (fpbw == NULL)
    {
       puts("Output binary file is having issues while opening terminating the program !");
       exit(1);
    }

      break;

    } else {
      
     puts(buffer);
}	
    }
    /* Opening file bin2.exe in “wb” mode for writing*/
   

    /* Ensure bin2.exe opened successfully*/

      
     /* Closing both the binary files */
     fclose(fpbr);
     fclose(fpbw);

     return 0;
}