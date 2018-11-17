/* ECP: FILEname=fig8_30.c */
   void
   PrintSpaces( int HowMany )
   {
       while( HowMany-- > 0 )
           putchar( ' ' );
   }

   void
   PutOut( const char Line[ ],  int Length )
   {
       int SmallGapLen;
       int NumGaps = 0;
       int NumSmallGaps;
       int LineLen = strlen( Line );
       int TotalSpaces;
       int i;

       for( i = 0; Line[ i ]; i++ )
           if( Line[ i ] == ' ' )
               NumGaps++;

       if( !NumGaps )
       {
           puts( Line );
           return;
       }

       TotalSpaces = Length - LineLen + NumGaps;
       SmallGapLen = TotalSpaces / NumGaps;
       NumSmallGaps = NumGaps - TotalSpaces % NumGaps;

       for( i = 0; Line[ i ]; i++ )
           if( Line[ i ] == ' ' )
               PrintSpaces( SmallGapLen + ( NumSmallGaps-- <= 0 ) );
           else
               putchar( Line[ i ] );
       putchar( '\n' );
   }
