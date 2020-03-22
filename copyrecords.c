#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int read_mode, write_mode, ci_mode, reversify;

  char key, ch, shift;
  int found, fnd, shiftkey, buffer_size, buffer_ci_size;
  long lSize, CiSize;

  double result, result_ci, result_out;

  /* Pointers for binary files*/
  FILE *infile, *cifile;

  if (argc == 1) // No argument is given through command line
  {
    read_mode = 0;
    write_mode = 0;
    ci_mode = 0;
    reversify = 0;
  }
  /**********************************************************************************************************/
  // Reading file in binary mode
  for (int i = 1; i < argc; i++)
  {
    if (0 == strcmp(argv[i], "-F"))
      found = i;
    read_mode = 1;
    break;
  }

  infile = fopen(argv[found + 1], "rb");

  if (infile == NULL)
  {
    //  puts("Input binary file is having issues while opening terminating the program !");
    // exit(1);
  }

  fseek(infile, 0, SEEK_END);
  lSize = ftell(infile);
  buffer_size = lSize;
  rewind(infile);

  // allocate memory to contain the whole file:
  char *buffer = (char *)malloc(buffer_size * sizeof(char));
  if (buffer == NULL)
  {
    fputs("Memory error", stderr);
    exit(2);
  }

  // copy the file into the buffer:

  result = fread(buffer, sizeof(char), buffer_size, infile);
  if (read_mode != 1)
  {
  }

  puts(buffer);
  free(buffer);
  /**********************************$$## CIPHER   FILE ##$$**********************************************/

  for (int j = 1; j < argc; j++)
  {
    if (0 == strcmp(argv[j], "-D"))
    {
      fnd = j;
      ci_mode = 1;
      break;
    }
  }

  if (ci_mode == 1)
  {
    cifile = fopen(argv[fnd + 1], "rb");

    if (cifile == NULL)
    {
      puts("Input Cipher file is having issues while opening terminating the program !");
      // exit(1);
    }

    fseek(cifile, 0, SEEK_END);
    CiSize = ftell(cifile);
    buffer_ci_size = CiSize;
    rewind(cifile);
    // allocate memory to contain the whole file
    // copy the file into the buffer:
    char *buffer_ci = (char *)malloc(buffer_ci_size * sizeof(char));

    if (buffer_ci == NULL)
    {
      fputs("Memory error", stderr);
      exit(2);
    }

    result_ci = fread(buffer_ci, sizeof(char), buffer_ci_size, cifile);

    for (int key = 0; key <= 25; key++)
    {
      char message[sizeof(buffer_ci_size)];
      strcpy(message, buffer_ci);
      for (int i = 0; message[i] != '\0'; i++)
      {
        ch = message[i];
        if (ch >= 'a' && ch <= 'z')
        {
          ch = ((ch + key - 97) % 26 + 97);
          message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
          ch = ((ch + key - 65) % 26 + 65);
          message[i] = ch;
        }
      }
      printf("\nDecoded text using Caeser Cipher Shift %d : \n %s\n", key, message);
    }

    free(buffer_ci);
    fclose(cifile);
  }
  /*  printf("Choose the correct Caeser Cipher Shift");
    scanf("%d\n", &shiftkey);
  }
  /**********************************************************************************************************/
  /* 
  for (int i = 1; i < argc; i++)
  {
    if (0 == strcmp(argv[i], "-r"))
      reversify = 1;
    break;
  }

  /************************************$$## Output File ##$$*************************************************/
  /* for (int i = 1; i < argc; i++)
  {
    if (0 == strcmp(argv[i], "-O"))
    {
      outfile = fopen(argv[i + 1], "wb");
      if (outfile == NULL)
      {
        puts("Output binary file is having issues while opening terminating the program !");
        exit(1);
      }
      write_mode = 1;
    }
  }

  if (write_mode == 1)
  {
    result_out = fwrite(buffer, sizeof(char), buffer_size, outfile);
  }
  else
  {
    // puts(buffer);
  }
  /**********************************************************************************************************/

  fclose(infile);
  // fclose(outfile);
  return 0;
}
