#include <stdio.h> 
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>
int main ( int argc, char *argv[] )
{
	int read_mode,write_mode,shift_type,reversify;
    
    char key,ch,shift;
    int shiftkey,buffer_size,buffer_com_size;
      long lSize;
     char * buffer;
     size_t result;
 
    /* Pointers for binary files*/
    FILE *fpbr, *fpdr,*fpbw;

  if (argc == 1)  // No argument is given through command line
    {
    	read_mode=0;
    	write_mode=0;
    	shift_type=0;
    	reversify=0;
      }
/**********************************************************************************************************/
    // Reading file in binary mode
     for (int i=1; i< argc; i++) 
    {
      if (0 == strcmp(argv[i], "-F"))

      { fpbr= fopen(argv[i+1], "rb+");
    
          if (fpbr == NULL)
    {
       puts("Input binary file is having issues while opening terminating the program !");
       exit(1);
    }

  fseek (fpbr , 0 , SEEK_END);
  lSize = ftell (fpbr);
  buffer_size=lSize;
  rewind (fpbr);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char)*lSize);
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:
  //result = fread (buffer,1,lSize,fpbr);
  //if (result != lSize) {fputs ("Reading error",stderr); exit (3);}  

  result = fread (buffer,sizeof(char),buffer_size,fpbr); //read 200 bytes to test only

  puts(buffer);
    
    }
    

char buffer_3[buffer_size];

    if (read_mode == 1)
    {
    
    }else{
     
    }	
    
/**********************************************************************************************************/
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
  while ((ch = fgetc(fpdr)) != EOF) {
 buffer_com_size++;
}
char buffer_2[buffer_com_size]; 
    if (shift_type == 1)
    {
      int count_com = fread(&buffer_2, sizeof(char),buffer_com_size,fpdr) ; 
            if (fpdr == NULL)
    {
       puts("Companion binary file is having issues while opening terminating the program !");
       exit(1);
    }

/**********************************************************************************************************/


    for(int key=0; key<=25;key++){
    char  message[buffer_com_size];
      strcpy(message,buffer_2); 
	for( int i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		  
		
		if(ch >= 'a' && ch <= 'z'){
			ch =((ch+key-97)%26 +97);
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){ 
			ch = ((ch+key-65)%26 +65);	
			message[i] = ch;
		}
	printf ("Decoded text using shift %d is %s\n",key,message);}
	} 

printf("Choose the correct Caeser Cipher Shift");
scanf("%d\n",&key);
    }else{
    key= 0;}
    
 
    /**********************************************************************************************************/
    for (int i=1; i< argc; i++) 
    {
      if (0 == strcmp(argv[i], "-r"))
      reversify=1;
    break;
    }

    /**********************************************************************************************************/
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
      //int cnt = fwrite(&buffer, sizeof(char),buffersize,fpbw) ; 
	    fputs(buffer_3,fpbw);
    }else{
     puts(buffer_3);
    }	 
    /**********************************************************************************************************/
     /* Closing both the binary files */
     fclose(fpbr);
     fclose(fpbw);
     fclose(fpdr);

     return 0;
}}
    