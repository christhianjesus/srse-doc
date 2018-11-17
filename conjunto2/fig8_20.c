/* ECP: FILEname=fig8_20.c */
   unsigned int
   Strlen( const char * const Str )
   {
       const char *Sp = Str;

       while( *Sp++ )
           ;

       return Sp - Str - 1;
   }
