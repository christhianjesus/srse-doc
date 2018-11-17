/* ECP: FILEname=fig13_36.c */
   #include <stdio.h>
   #include <sys/types.h>
   #include <signal.h>

   pid_t Pid;

   void
   Handler1( void )
   {
       printf( "Entering Handler1\n" );
       kill( Pid, SIGUSR2 );
       printf( "Leaving Handler1\n" );
   }

   void
   Handler2( void )
   {
       printf( "Entering Handler2\n" );
       kill( Pid, SIGUSR1 );
       printf( "Leaving Handler2\n" );
   }

   main( void )
   {
       Pid = getpid( );
       signal( SIGUSR1, Handler1 );
       signal( SIGUSR2, Handler2 );
       kill( Pid, SIGUSR1 );
       return 0;
   }
