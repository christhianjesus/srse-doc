/* ECP: FILEname=fig9_18.c */
   /* Shellsort An Array Of Unknowns. */
   /* Uses Only 2N Block Copies. */

   void
   Shellsort( void *A, const unsigned int N, const size_t Size,
           int Cmp( const void *, const void * ) ) {

       unsigned int Gap;
       void *Tmp;
       unsigned int i, j;                   /* Loop Counters */
       void **Ptr;          /* Array Of Pointers To Unknowns */
       void *ACopy;                          /* Sorted Array */

       /* Allocate And Initialize Pointers for Indirect Sort */
       if( ( Ptr = malloc( N * sizeof( void * ) ) ) == NULL )
           Error( "Out of memory" );
       if( ( ACopy = malloc( N * Size ) ) == NULL )
           Error( "Out of memory" );
       for( i = 0; i < N; i++ )
           Ptr[ i ] = A + i * Size;

           /* Indirect Shellsort */
       for( Gap = N/2; Gap > 0; Gap = Gap == 2 ? 1 : Gap / 2.2 )
           for( i = Gap; i < N; i++ )
           {
               Tmp = Ptr[ i ];
               for( j = i; j >= Gap &&
                      Cmp( Tmp, Ptr[ j - Gap ] ) < 0; j -= Gap )
                   Ptr[ j ] = Ptr[ j - Gap ];
               Ptr[ j ] = Tmp;
           }

       for( i = 0; i < N; i++ )       /* Make Sorted Array */
           memcpy( ACopy + i * Size, Ptr[ i ], Size );

          /* Copy It Back */
       memcpy( A, ACopy,  N * Size );

       free( ACopy ); free( Ptr );    /* Clean Up */
   }
