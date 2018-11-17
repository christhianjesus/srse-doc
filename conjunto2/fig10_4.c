/* ECP: FILEname=fig10_4.c */
   int
   CheckBalance( void )
   {
       Stack S = StMakeEmpty( NULL );
       Symbol Last = { 0, 1 }, Match;
       int Errors = 0;

       while( ( Last.Sym = getchar( ) ) != EOF )
           switch( Last.Sym )
           {
             case '\n':
               Last.Line++;
               break;
             case '(': case '[': case '{':
               Push( Last, S );
               break;
             case ')': case ']': case '}':
               if( StIsEmpty( S ) )
               {
                   Errors++;
                   printf( "Extraneous %c at line %d\n",
                       Last.Sym, Last.Line );
               }
               else
               {
                   Match = Top( S ); Pop( S );
                   if( CheckMatch( &Match, &Last ) )
                       Errors++;
               }
               break;
             default:
               break;
           }

       while( !StIsEmpty( S ) )      /* Unmatched Symbols */
       {
           Errors++;
           Match = Top( S ); Pop( S );
           printf( "Unmatched %c at line %d\n",
                       Match.Sym, Match.Line );
       }
       StRecycle( S );
       return Errors;
   }
