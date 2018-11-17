/* ECP: FILEname=fig9_16.c */
   /* Shellsort An Array Of Blocks. */
   /* Avoid Excessive Copying And Extra Array Of Blocks */

   void
   Shellsort( Block A[ ], const unsigned int N )
   {
       unsigned int Gap;
       Block *Tmp;
       unsigned int i, j, NextJ;            /* Loop Counters */
       Block **Ptr;            /* Array Of Pointers To Block */
       int *Rank;    /* Array Listing Correct Final Position */
       Block ShuffleTmp; /* Temp for The Final Rearrangement */

       /* Allocate And Initialize Pointers for Indirect Sort */
       if( ! ( Ptr = malloc( N * sizeof( struct Block * ) ) ) )
           Error( "Out of memory" );
       if( ( Rank = malloc( N * sizeof( int ) ) ) == NULL )
           Error( "Out of memory" );
       for( i = 0; i < N; i++ )
           Ptr[ i ] = &A[ i ];

       /* Indirect Shellsort (Omitted -- Figure 9.15, 19-27) */
           /* Determine Correct Positions */
       for( i = 0; i < N; i++ )
           Rank[ i ] = Ptr[ i ] - &A[ 0 ];

           /* Shuffle It Back */
       for( i = 0; i < N; i++ )
           if( Rank[ i ] != i )
           {
               ShuffleTmp = A[ i ];
               for( j = i; Rank[ j ] != i; j = NextJ )
               {
                   A[ j ] = A[ Rank[ j ] ];
                   NextJ = Rank[ j ];
                   Rank[ j ] = j;
               }
               A[ j ] = ShuffleTmp;
               Rank[ j ] = j;
           }

       free( Rank ); free( Ptr ); /* Clean Up */
   }
