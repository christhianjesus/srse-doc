/* ECP: FILEname=fig13_25.c */
   /* Fill The Structure Referenced By Buf */

   int
   Parse( char *TheLine, FullCommand *Buf )
   {
       int CommandNum = 0, Token;
       char Str[ MaxLineLen ];
       int NumStr = 0;     /* # Of Strings In Current Command */

       Buf->NumPipes = Buf->Background = 0;
       strcpy( Buf->InFile, "" );
       strcpy( Buf->OutFile, "" );

       for( ; TheLine  = GetToken( TheLine, Str, &Token ); )
           switch( Token )
           {
             default:
             case Error:
               printf( "Syntax error\n" );
               return -1;
             case From:
               strcpy( Buf->InFile, Str );
               break;
             case To:
               strcpy( Buf->OutFile, Str );
               break;
             case Amper:
               Buf->Background++;
               break;
             case Pipe:
               Buf->NumPipes++;
             case Eoln:
               Buf->Commands[ CommandNum++ ][ NumStr ] = NULL;
               NumStr = 0;
               break;
             case Word:
               Buf->Commands[ CommandNum ][ NumStr++ ] =
                   Strdup( Str );   /* Note: This Is A Memory Leak */
               break;
           }
       return 0;
   }
