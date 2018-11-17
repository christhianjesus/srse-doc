/* ECP: FILEname=fig8_9.c */
   #include <stdio.h>

   main( void )
   {
       int Ch;       /* Must Be An int!! */

       while( ( Ch = getchar( ) ) != EOF )  /* ( ) Are Needed!! */
       {
           putchar( Ch );
           if( Ch == '\n' )
               putchar( '\n' );
       }

       return 0;
   }
