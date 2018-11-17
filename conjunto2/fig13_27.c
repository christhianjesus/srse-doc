/* ECP: FILEname=fig13_27.c */
   void
   SetFiles( FullCommand *Buf )
   {
       if( Buf->InFile[ 0 ] )
           if( freopen( Buf->InFile, "r", stdin ) == NULL )
           {
               perror( Buf->InFile );
               _exit( 127 );
           }

       if( Buf->OutFile[ 0 ] )
           if( freopen( Buf->OutFile, "w", stdout ) == NULL )
           {
               perror( Buf->OutFile );
               _exit( 127 );
           }
   }

   void
   UsePipe( int Fd[ 2 ], int WhichEnd )
   {
       dup2( Fd[ WhichEnd ], WhichEnd );
       close( Fd[ 0 ] );
       close( Fd[ 1 ] );
   }
