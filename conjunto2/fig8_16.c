/* ECP: FILEname=fig8_16.c */
   unsigned int
   Strlen( const char Str[ ] )
   {
       int i = -1;

       while( Str[ ++i ] )
           ;

       return i;
   }
