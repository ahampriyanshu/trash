#include <stdio.h> 
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>

int decrypt(string text,int s)
{
	string result="";
	//traverse text
	for(int i=0;i<text.length();i++)
	{
		//apply transformation to each character
		//Encrypt Uppercase letters
		if(isalpha(text[i]))
		{
		    if(isupper(text[i]))
			result+=char(int(text[i]+s-65)%26 +65);
	//Encrypt Lowercase letters
	else
		result+=char(int(text[i]+s-97)%26 +97);
	}
	else
	{result += text[i];}
	}
	//Return the resulting string
	return result;
}

int main ( int argc, char *argv[] )
{
	int read_mode,write_mode,shift_type,reversify;

    char ch;
    char shift;

    char buffer[1500]; 
	
	
	
    /*Char array to store string */
    char str[24];

    /* Pointers for both binary files*/
    FILE *fpbr, *fpdr,*fpbw;

  if (argc == 1)  // create pin
    {
    	read_mode=0;
    	write_mode=0;
    	shift_type=0;
    	reversify=0;
      }

    // Reading file in binary mode
     for (int i=1; i< argc; i++) 
    {
      if (0 == strcmp(argv[i], "-F"))

      { fpbr= fopen(argv[i+1], "rb");
    
          if (fpbr == NULL)
    {
       puts("Input binary file is having issues while opening terminating the program !");
       exit(1);
    }
     read_mode = 1;
     reversify = 0;
    }
    }

    if (read_mode == 1)
    {
      int count = fread(&buffer, sizeof(char),500,fpbr) ; 
    }else{
     scanf("%s",buffer);
    }	
    
         for (int i=1; i< argc; i++) 
    {
      if (0 == strcmp(argv[i], "-D"))

      { fpdr= fopen(argv[i+1], "rb");
    
          if (fpdr == NULL)
    {
       puts("Companion binary file is having issues while opening terminating the program !");
       exit(1);
    }
     shift_type=1;
    }
    }

    if (shift_type == 1)
    {
      int count_com = fread(&buffer_2, sizeof(char),1500,fpdr) ; 
            if (fpdr == NULL)
    {
       puts("Companion binary file is having issues while opening terminating the program !");
       exit(1);
    }
    decrypt(text, 26-s);
    }


    if (reversify ==1)
    
    /*now producing the output  file */

    for (int i=1; i< argc; i++) 
    {
      if (0 == strcmp(argv[i], "-O"))

      { fpbw= fopen(argv[i+1], "wb");
    
          if (fpbw == NULL)
    {
       puts("Output binary file is having issues while opening terminating the program !");
       exit(1);
    }
     write_mode=1;
    }
    }

    if (write_mode == 1)
    {
      //int cnt = fwrite(&buffer, sizeof(char),500,fpbw) ; 
	    fputs(buffer,fpbw);
    }else{
     puts(buffer);
    }	
    /* Opening file bin2.exe in “wb” mode for writing*/
   

    /* Ensure bin2.exe opened successfully*/

      
     /* Closing both the binary files */
     fclose(fpbr);
     fclose(fpbw);

     return 0;
}
