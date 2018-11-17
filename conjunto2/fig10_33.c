/* ECP: FILEname=fig10_33.c */
   typedef struct Cell
   {
       int Number;
       struct Cell *Next;
   } CellType;

   CellType *
   GetCell( int CellNo )
   {
       CellType *CellPtr = malloc( sizeof( CellType ) );

       if( CellPtr == NULL )
           Error( "Out of memory" );

       CellPtr->Number = CellNo;
       return CellPtr;
   }

   int
   Jos( int People, int Passes )
   {
       CellType *BeforeBall, *Last, *First, *Loser;
       int i;

           /* Create The List */
       First = Last = GetCell( 1 );
       for( i = 2; i <= People; i++ )
           Last = Last->Next = GetCell( i );

       Last->Next = First;        /* Make List Circular */

       for( BeforeBall = Last; People != 1; People-- )
       {
               /* Pass The Ball */
           for( i = 0; i < Passes; i++ )
               BeforeBall = BeforeBall->Next;

               /* Remove A Player */
           Loser = BeforeBall->Next;
           BeforeBall->Next = Loser->Next;
           free( Loser );	/* See Text Warning */
       }
       return BeforeBall->Number;
   }
