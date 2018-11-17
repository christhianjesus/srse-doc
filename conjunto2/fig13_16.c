/* ECP: FILEname=fig13_16.c */
   #include <stdio.h>
   #include <sys/types.h>
   #include <sys/wait.h>
   #include <unistd.h>
   #include <errno.h>

   int
   SimpleSystem( const char *Command )
   {
       pid_t Pid;
       int Status;

       if( Command == NULL )
           return 1;

       Pid = fork( );
       if( Pid < 0 )	/* Error */
           return -1;

       if( Pid == 0 )	/* Child */
       {
           execl( "/bin/sh", "sh", "-c", Command, NULL );
           _exit( 127 );       /* execl Failed; Give Up On Child */
       }

       /* else  Parent */
       waitpid( Pid, &Status, 0 );
       return Status;
   }
