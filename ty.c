#include <stdio.h>

int main(int argc, char *argv[])
{
   FILE *fp;
   char line[100];
   int  i;
   float f;
   double d;

   // fp = fopen("textFile", "r");
   fp = fopen("outFile", "r");

   fscanf(fp, "%s", &line[0]);
   fscanf(fp, "%d", &i);
   fscanf(fp, "%f", &f);
   fscanf(fp, "%lf", &d);
   return 0;
}
