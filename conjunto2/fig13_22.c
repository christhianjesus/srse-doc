/* ECP: FILEname=fig13_22.c */
   #include <stdio.h>
   #include <signal.h>
   #include <setjmp.h>
   #include <stdlib.h>

   static sigjmp_buf RestartLoop;

   static void
   IntrHandler( int SigNum )
   {
       static int NumCalls = 0;

       if( ++NumCalls == 3 )   /* Allow Three Per Program */
       {
           fprintf( stderr, "Quitting...\n" );
           exit( 0 );      
       }
       fprintf( stderr, "Caught an interrupt: resetting\n" );
       siglongjmp( RestartLoop, NumCalls );
   }

   main( void )
   {
       sigsetjmp( RestartLoop, 1 );
       signal( SIGINT, IntrHandler );
       for( ; ; )
           DoCommands( );

       return 0;
   }
