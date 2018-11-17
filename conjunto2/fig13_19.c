/* ECP: FILEname=fig13_19.c */
   #include <signal.h>  /* Other Includes Omitted For Brevity */

   int
   RealSystem( const char *Command )
   {
       pid_t Pid;
       int Status;
       void ( *SaveIntr )( ), ( *SaveQuit )( );

       if( Command == NULL )
           return 1;

       SaveIntr = signal(  SIGINT, SIG_IGN );      /* Ignore */
       SaveQuit = signal(  SIGQUIT, SIG_IGN );    /* Signals */

       Pid = fork( );
       if( Pid < 0 )	/* Error */
           return -1;

       if( Pid == 0 )	/* Child */
       {
           signal( SIGINT, SaveIntr );            /* Restore */
           signal( SIGQUIT, SaveQuit );           /* Signals */

           execl( "/bin/sh", "sh", "-c", Command, NULL );
           _exit( 127 );   /* execl Failed; Give Up On Child */
       }
          /* Parent */
       waitpid( Pid, &Status, 0 );

       signal( SIGINT,  SaveIntr );               /* Restore */
       signal( SIGQUIT, SaveQuit );               /* Signals */

       return Status;
   }
