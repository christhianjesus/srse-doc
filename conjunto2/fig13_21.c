/* ECP: FILEname=fig13_21.c */
   #include <stdio.h>
   #include <signal.h>
   #include <setjmp.h>
   #include <stdlib.h>

   static jmp_buf RestartLoop;

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
       longjmp( RestartLoop, NumCalls );
   }

   main( void )
   {
       setjmp( RestartLoop );
       signal( SIGINT, IntrHandler );
       for( ; ; )
           DoCommands( );

       return 0;
   }
