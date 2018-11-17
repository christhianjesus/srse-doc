/* ECP: FILEname=fig12_20.c */
   void
   Wc( FILE *Ifp )
   {
       int Ch, InWord = 0, Words = 0, Lines = 0, Chars = 0;

       while( ( Ch = getc( Ifp ) ) != EOF )
       {
           Chars++;
           if( Ch == '\n' )
               Lines++;
           if( isspace( Ch ) )
               InWord = 0;
           else if( !InWord )
           {
               /* New Word Seen */
               InWord = 1;
               Words++;
           }
       }

       if( Lflag ) printf( "%8d", Lines );
       if( Wflag ) printf( "%8d", Words );
       if( Cflag ) printf( "%8d", Chars );
   }
