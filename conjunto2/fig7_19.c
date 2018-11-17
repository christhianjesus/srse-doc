/* ECP: FILEname=fig7_19.c */
   int
   IsEmpty( BoardType Board, int Row, int Column )
   {
       return Board[ Row ][ Column ] == Empty;
   }

   void
   MakeEmpty( BoardType Board )
   {
       int Row, Column;

       for( Row = 0; Row < Bsize; Row++ )
           for( Column = 0; Column < Bsize; Column++ )
               Board[ Row ][ Column ] = Empty;
   }

   void
   PrintBoard( BoardType Board )
   {
       int Row, Column;

       printf( "---\n" );
       for( Row = 0; Row < Bsize; Row++ )
       {
           for( Column = 0; Column < Bsize; Column++ )
               if( Board[ Row ][ Column ] == Empty )
                   printf( " " );
               else if( Board[ Row ][ Column ] == Computer )
                   printf( CompColor == X ? "X" : "O" );
               else
                   printf( CompColor != X ? "X" : "O" );
           printf( "\n" );
       }
       printf( "---\n" );
   }
