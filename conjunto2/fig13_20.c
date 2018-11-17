/* ECP: FILEname=fig13_20.c */
   /* Simple Demonstration Of Signal Handling */
   /* Buffers Are Flushed On Interrupt */

   #include <signal.h>
   #include <stdio.h>
   #include <stdlib.h>
   #include <unistd.h>

   void
   Doexit( void )
   {
       exit( SIGINT );     /* Flush Buffers */
   }

   main( void )
   {
       signal( SIGINT, Doexit );
       for( ; ; )
       {
           sleep( 1 );
           printf( "junk" );
       }
       return 0;
   }
