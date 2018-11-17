/* ECP: FILEname=fig8_15.c */
   unsigned int
   Strlen( const char Str[ ] )
   {
       int i;

       for( i = 0; Str[ i ] != '\0'; i++ )
           ;

       return i;
   }
