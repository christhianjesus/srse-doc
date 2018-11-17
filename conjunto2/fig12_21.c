/* ECP: FILEname=fig12_21.c */
   #include <stdio.h>
   #include <stdlib.h>

   main( int argc, char *argv[ ], char *envp[ ] )
   {
       int i;

       for( i = 0; envp[ i ] != NULL; i++ )
           printf( "%s\n", envp[ i ] );

       printf( "TERMINAL TYPE IS: %s\n", getenv( "TERM" ) );

       return 0;
   }
