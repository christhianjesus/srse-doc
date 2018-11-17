/* ECP: FILEname=fig8_11.c */
   int
   ToUpper( char Ch )
   {
       static const char Lower[ ] = "abcdefghijklmnopqrstuvwxyz";
       static const char Upper[ ] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

       int i;

       for( i = 0; Lower[ i ] != '\0'; i++ )
           if( Lower[ i ] == Ch )
               return Upper[ i ];

       return Ch;
   }
