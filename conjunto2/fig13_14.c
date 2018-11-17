/* ECP: FILEname=fig13_14.c */
   #include <stdio.h>
   #include <sys/types.h>
   #include <unistd.h>

   main( void )
   {
       pid_t Pid;
       long int i;

       if( ( Pid = fork( ) ) == -1 )
       {
           perror( "" );
           exit( -1 );
       }

       if( Pid == 0 )
           printf( "I am the child; my parent is %d.", getppid( ) );
       else
           printf( "I am the parent; my child is %d.", Pid );

       /* Both Processes Execute Their Own Copies Of this */
       printf( "  My process id is %d.\n", getpid( ) );
       fflush( stdout );
       for( i = 0; i < 3000000; i++ )
           if( i % 1000000 == 0 )
           {
               printf( "%s\n", Pid ? "Parent" : "Child" );
               fflush( stdout );
           }

       return 0;
   }
