/* ECP: FILEname=fig8_31.c */
   /* Print out Starting And Ending time. */
   /* Incorrect: ctime Returns A Pointer To static Data */

   #include <time.h>
   #include <stdio.h>

   main( void )
   {
       time_t Before, After;
       char *Bct, *Act;

       time( &Before );
       Bct = ctime( &Before );

       sleep( 5 );

       time( &After );
       Act = ctime( &After );

       printf( "Before: %s", Bct );
       printf( "After:  %s", Act );

       return 0;
   }
