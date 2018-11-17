/* ECP: FILEname=fig10_25.c */
   static void
   Rehash( HashTbl H )
   {
       unsigned int i, Pos, OldSize = H->MaxSize;
       Cell *OldArray = H->Array;
       const Cell InitCell = { NULL, NotFound };

       H->MaxSize = NextPrime( 2 * OldSize );
       H->Array = malloc( sizeof( Cell ) * H->MaxSize );
       if( H->Array == NULL )
       {
           printf( "Can not rehash\n" );
           exit( -1 );
       }
       H->Size = 0;
       for( i = 0; i < H->MaxSize; i++ )
           H->Array[ i ] = InitCell;

           /* Reinsert Old Elements Into new Table */
       for( i = 0; i < OldSize; i++ )
           if( OldArray[ i ].Num >= 0 )
           {
               Pos = FindPos( OldArray[ i ].Word, H );
               H->Array[ Pos ] = OldArray[ i ];
               H->Size++;
           }

       free( OldArray );
   }
