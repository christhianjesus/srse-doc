/* ECP: FILEname=fig8_17.c */
   char *
   Strcpy( char Lhs[ ], const char Rhs[ ] )
   {
       int i;

       if( Lhs != Rhs )
           for( i = 0; Lhs[ i ] = Rhs[ i ]; i++ )
               ;

       return Lhs;
   }
