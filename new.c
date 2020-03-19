#include <stdio.h> 
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>
int main ( int argc, char *argv[] )
{
	int read_mode,write_mode,ci_mode,reversify;
    
    char key,ch,shift;
    int found,fnd;
    int shiftkey,buffer_size,buffer_ci_size;
    long lSize,CiSize;
    char *buffer;
    char *buffer_ci;
    size_t result;
    size_t result_ci;
 
    /* Pointers for binary files*/
    FILE *fpbr, *cifile,*fpbw;

  if (argc == 1)  // No argument is given through command line
    {
    	read_mode=0;
    	write_mode=0;
    	ci_mode=0;
    	reversify=0;
      }
/**********************************************************************************************************/
    // Reading file in binary mode
    for (int i=1; i< argc; i++) 
    {
      if (0 == strcmp(argv[i], "-F"))
         found = i;
         read_mode = 1;
         break;
    }
   
  

   fpbr= fopen(argv[found+1], "rb");
    
          if (fpbr == NULL)
    {
     //  puts("Input binary file is having issues while opening terminating the program !");
      // exit(1);
    }
    
 fseek (fpbr , 0 , SEEK_END);
  lSize = ftell (fpbr);
  buffer_size=lSize;
  rewind (fpbr);

  // allocate memory to contain the whole file:
  buffer = (char*) malloc (sizeof(char) * (buffer_size+1000));
  if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

  // copy the file into the buffer:

  result = fread (buffer,sizeof(char),buffer_size,fpbr); 

  puts(buffer);
  

    if (read_mode != 1)
    {
        scanf("%s",buffer);
    }	
    
/**********************************$$## CIPHER   FILE ##$$**********************************************/
    
     for (int j=1; j< argc; j++) 
    {
      if (0 == strcmp(argv[j], "-D"))
         fnd = j;
         ci_mode = 1;
         break;
    }

   
   cifile= fopen(argv[fnd+1], "rb");
    
          if (cifile == NULL)
    {
       puts("Input Cipher file is having issues while opening terminating the program !");
      // exit(1);
    }
    
  fseek (cifile , 0 , SEEK_END);
  CiSize = ftell (cifile);
  buffer_ci_size=CiSize;
  rewind (cifile);
  // allocate memory to contain the whole file
  // copy the file into the buffer:

 result_ci = fread (buffer_ci,sizeof(char),buffer_ci_size,cifile); 
 

    for(int key=0; key<=25;key++){
    char  message[sizeof(buffer_ci_size)];
      strcpy(message,buffer_ci); 
	for( int i = 0; message[i] != '\0'; i++){
		ch = message[i];
	  if(ch >= 'a' && ch <= 'z'){
			ch =((ch+key-97)%26 +97);
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){ 
			ch = ((ch+key-65)%26 +65);	
			message[i] = ch;
		}}
	 printf ("\nDecoded text using Caeser Cipher Shift %d : \n %s\n",key,message);
	} 

    printf("Choose the correct Caeser Cipher Shift");
    scanf("%d\n",&shiftkey);
    
    
 
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
	   // fputs(buffer_3,fpbw);
    }else{
     // puts(buffer_3);
    }	 
    /**********************************************************************************************************/
     /* Closing both the binary files */
     fclose(fpbr);
     fclose(fpbw);
     fclose(cifile);

     return 0;
}
    
