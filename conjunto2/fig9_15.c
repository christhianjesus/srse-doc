/* ECP: FILEname=fig9_15.c */
   /* Shellsort An Array Of Blocks. */
   /* Uses Only 2N Block Copies. */

   void
   Shellsort( Block A[ ], const unsigned int N )
   {
       unsigned int Gap;
       Block *Tmp;
       unsigned int i, j;                    /* Loop Counters */
       Block **Ptr;             /* Array Of Pointers To Block */
       Block *ACopy;                          /* Sorted Array */

       /* Allocate And Initialize Pointers for Indirect Sort */
       if( ! ( Ptr = malloc( N * sizeof( struct Block * ) ) ) )
           Error( "Out of memory" );
       if( ! ( ACopy = malloc( N * sizeof( struct Block ) ) ) )
           Error( "Out of memory" );
       for( i = 0; i < N; i++ )
           Ptr[ i ] = &A[ i ];

           /* Indirect Shellsort */
       for( Gap = N/2; Gap > 0; Gap = Gap == 2 ? 1 : Gap / 2.2 )
           for( i = Gap; i < N; i++ )
           {
               Tmp = Ptr[ i ];
               for( j = i; j >= Gap &&
                      Tmp->Key < Ptr[ j - Gap ]->Key; j -= Gap )
                   Ptr[ j ] = Ptr[ j - Gap ];
               Ptr[ j ] = Tmp;
           }

       for( i = 0; i < N; i++ )       /* Make Sorted Array */
           ACopy[ i ] = *Ptr[ i ];

       for( i = 0; i < N; i++ )       /* Copy It Back */
           A[ i ] = ACopy[ i ];

       free( ACopy ); free( Ptr );    /* Clean Up */
   }
