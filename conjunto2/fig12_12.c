/* ECP: FILEname=fig12_12.c */
   /* Skip Over Current Lines And Any Subsequent Blank Lines */

   void
   SkipLines( FILE *Fp )
   {
       int Ch;

       while(  ( Ch = getc( Fp ) ) != EOF )
           if( Ch == '\n' )    /* End Of Current Line */
           {
                   /* Skip Over Newlines */
               while( ( Ch = getc( Fp ) ) != EOF && Ch == '\n' )
                   ;

                   /* Push Back Non-Newline */
               if( Ch != EOF )
                   ungetc( Ch, Fp );

               break;
           }
   }
