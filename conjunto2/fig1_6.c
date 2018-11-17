/* ECP: FILEname=fig1_6.c */
   /* Return 1 if Str1 And Str2 Are Equal */

   int
   IsEqual( char Str1[ ], char Str2[ ] )
   {
       int i;

       for( i = 0; Str1[ i ] == Str2[ i ]; i++ )
           if( Str1[ i ] == '\0' )
               return 1;      /* Equal Strings */

       return 0;                  /* Not Equal */
   }
