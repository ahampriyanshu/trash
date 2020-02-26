#include <stdio.h> 
#include <string.h> 
#include <ctype.h>


int main( int argc, const char** argv)
{
	int stdin_mode,stdout_mode,com_file,reversify;

    char ch;
    char *inputfile,*outputfile,*comparefile;
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

  if (stdin_mode=0)
  {
  	for (int i = 0; i < argc; i++)
  	{
  		//if ( argv[i] == "-F")
  			printf("%s\n",argv[i] );
  			//inputfile = argv[i+1];
  }

    printf("hello are you there");
    
    /* Open for bin1.exe file in rb mode */
    fpbr = fopen(inputfile, "rb");

    /* test logic for successful open*/
    if (fpbr == NULL)
    {
        puts("Input Binary file is having issues while opening terminating the program !");
      
    }

    int count = fread(&buffer, sizeof(char),1500, fpbr);
	

	// printf("Data read from file: %s \n", buffer);
 	// printf("Elements read: %d", count);
   // shift = decode ();
  //  printf("Cyper shift is %d",shift);

    /* Opening file bin2.exe in “wb” mode for writing*/
    fpbw= fopen("decodedfile.txt", "wb");

    /* Ensure bin2.exe opened successfully*/
    if (fpbw == NULL)
    {
       puts("Output binary file is having issues while opening going to stdout mode");
    }
    else{
             // decode(str, shift);
             fputs(buffer, fpbw);
         }
     /* Closing both the binary files */
     fclose(fpbr);
     fclose(fpbw);

     return 0;
 }
}