/* ECP: FILEname=fig12_13.c */
   #include <stdio.h>
   #include <string.h>

   /* Copy From Sourcefile To Destfile And return The Number */
   /* Of Characters Copied; -1 For Errors */

   int
   Copy( const char *DestFile, const char *SourceFile )
   {
       int CharsCounted = 0;
       int Ch;
       FILE *Sfp, *Dfp;

       if( strcmp( SourceFile, DestFile ) == 0 )
       {
           printf( "Can not copy to self\n" );
           return -1;
       }

       if( ( Sfp = fopen( SourceFile, "r" ) ) == NULL )
       {
           printf( "Can not open input file %s\n", SourceFile );
           return -1;
       }

       if( ( Dfp = fopen( DestFile, "w" ) ) == NULL )
       {
           printf( "Can not open output file %s\n", DestFile );
           fclose( Sfp ); return -1;
       }

       while( ( Ch = getc( Sfp ) ) != EOF )
           if( putc( Ch, Dfp ) == EOF )
           {
               printf( "Unexpected error during write.\n" );
               break;
           }
           else
               CharsCounted++;

       fclose( Sfp );
       fclose( Dfp );
       return CharsCounted;
   }
