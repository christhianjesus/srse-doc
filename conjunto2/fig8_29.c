/* ECP: FILEname=fig8_29.c */

   /* If Word Is FLUSH, Then Output The Current Line. */
   /* Otherwise, Add Word To End Of Line; if It Doesn't Fit */
   /* Then Output The Current Line ( Padded ) */

   void
   Justify( const char Word[ ] )
   {
       static char CurrentLine[ LineLen + 1 ] = "";
       static int CharsHeld = 0;
       static int Indent = IndentLen;  /* Current Amount To Indent */
       static int LineLimit = LineLen - IndentLen;
       int WordLen = strlen( Word );

       if( strcmp( Word, FLUSH ) == 0 )
       {
               /* Print The Pending Line. */
           PrintSpaces( Indent );
           puts( CurrentLine );                 /* No Padding */
           Indent = IndentLen;               /* For Next Line */
       }
       else
       if( CharsHeld + WordLen < LineLimit )
       {
               /* Word Fits On The Line */
           if( CharsHeld ) /* Toss in Blank if Not First Word */
           {
               strcat( CurrentLine, " " );
               CharsHeld++;
           }
           strcat( CurrentLine, Word );
           CharsHeld += WordLen;
           return;
       }
       else
       {       /* Print The Pending Line With Padding*/
           PrintSpaces( Indent );
           PutOut( CurrentLine, LineLimit );
           Indent = 0;           /* Next Line Is Not Indented */
       }

               /* Start Up The Next Line */
       strcpy( CurrentLine, Word );
       CharsHeld = WordLen;
       LineLimit = LineLen - Indent;
   }
