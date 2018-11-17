/* ECP: FILEname=fig13_28.c */
   int
   RunCommand( FullCommand *Buf )
   {
       pid_t Pid;
       int Fd[ 2 ];
       int i;

       if( ( Pid = fork( ) ) < 0 )	/* Error */
           return -1;

       if( Pid == 0 )	/* Child */
       {
           SetFiles( Buf );
           if( !Buf->Background )
           {
               signal( SIGINT, SIG_DFL );   /* Restore Signals */
               signal( SIGQUIT, SIG_DFL );  /* Before Exec */
           }

           /* For Each pipe, We Need An Additional Process */
           for( i = Buf->NumPipes; i > 0 ; i-- )
           {
               if( pipe( Fd ) < 0 )
               {
                   perror( Buf->Commands[ 0 ][ 0 ] );
                   _exit( 127 );
               }
               if( ( Pid = fork( ) ) < 0 )
                   return -1;

               UsePipe( Fd, Pid ? STDIN_FILENO : STDOUT_FILENO );
               if( Pid != 0 )	/* Parent */
                   break;
           }
           execvp( Buf->Commands[ i ][ 0 ], Buf->Commands[ i ] );
           perror( Buf->Commands[ i ][ 0 ] );
           _exit( 127 );     /* execl Failed; Give Up On Child */
       }

       /* Shell Process: Note Pid Is Last Command In Pipeline */
       if( !Buf->Background )
           waitpid( Pid, NULL, 0 );

       return 0;
   }
