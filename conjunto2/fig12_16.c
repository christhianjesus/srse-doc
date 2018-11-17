/* ECP: FILEname=fig12_16.c */
   #include <stdio.h>
   #include <stdlib.h>

   /* Print Last HowMany Characters in FileName */

   void
   LastChars( const char *FileName, unsigned int HowMany )
   {
       FILE *Fp;
       char *Buffer;
       int CharsRead;
       int FileSize;

       if( ( Buffer = malloc( HowMany ) ) == NULL )
       {
           fprintf( stderr, "Out of space!!\n" );
           return;
       }

       if( ( Fp = fopen( FileName, "rb" ) ) == NULL )
           fprintf( stderr, "Can not open %s\n", FileName );
       else
       {
               /* Get The Size Of The File */
           fseek( Fp, 0, SEEK_END );
           FileSize = ftell( Fp );
           if( FileSize < HowMany )
               HowMany = FileSize;

               /* Copy Its End */
           fseek( Fp, - HowMany, SEEK_END );
           CharsRead = fread( Buffer, 1, HowMany, Fp );
           fwrite( Buffer, 1, CharsRead, stdout );
           fclose( Fp );
       }

       free( Buffer );
   }
