#include <stdio.h>
#include <stdlib.h>

main()
{
   FILE *fpipe;
   char *command="ls -l";
   char line[256];

   if ( !(fpipe = (FILE*)popen(command,"r")) )
   {  // If fpipe is NULL
      perror("Problems with pipe");
      exit(1);
   }

   while ( fgets( line, sizeof line, fpipe))
   {
     printf("%s", line);
   }
   pclose(fpipe);
}
                
