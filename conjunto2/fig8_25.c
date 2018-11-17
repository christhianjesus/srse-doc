/* ECP: FILEname=fig8_25.c */
   int
   CountChars( const char *Str, char SearchChar )
   {
       unsigned int Matches = 0;

       if( Str != NULL )
           while( ( Str = Strchr( Str, SearchChar ) ) != NULL )
           {
               Str++;
               Matches++;
           }

       return Matches;
   }
