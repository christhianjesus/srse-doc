/* ECP: FILEname=fig8_18.c */
   int
   Strcmp( const char Lhs[ ], const char Rhs[ ] )
   {
       int i;

       for( i = 0; Lhs[ i ] == Rhs[ i ]; i++ )
           if( Lhs[ i ] == '\0' )
               return 0;

       return Lhs[ i ] - Rhs[ i ];
   }
