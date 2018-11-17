/* ECP: FILEname=fig13_26.c */
   /* Print A Prompt */
   void
   Prompt( int Num )
   {
       printf( "[%d] ", Num );
       fflush( stdout );
   }

   /* Simple main */
   main( void )
   {
       FullCommand OneComm;
       char OneLine[ MaxLineLen ];
       int RetCode;
       int CommandNum = 1;
       
       signal( SIGINT, SIG_IGN );  /* Ignore Signals */
       signal( SIGQUIT, SIG_IGN ); 

       for( Prompt( CommandNum ); GetLine( OneLine ) != NULL; )
       {
           if( OneLine[ 0 ] != '\n' )
           {
               CommandNum++;
               Parse( OneLine, &OneComm );
               RunCommand( &OneComm );
           }
           Prompt( CommandNum );
       }

       return 0;
   }
