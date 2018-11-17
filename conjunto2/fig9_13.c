/* ECP: FILEname=fig9_13.c */
   /* Shellsort An Array Of Blocks. */
   /* Very Slow Because Of Block Copies. */

   void
   Shellsort( Block A[ ], const unsigned int N )
   {
       unsigned int Gap;
       Block Tmp;
       unsigned int i, j;		/* Loop Counters */

       for( Gap = N/2; Gap > 0; Gap = Gap == 2 ? 1 : Gap / 2.2 )
           for( i = Gap; i < N; i++ )
           {
               Tmp = A[ i ];
               for( j = i; j >= Gap &&
                        Tmp.Key < A[ j - Gap ].Key; j -= Gap )
                   A[ j ] = A[ j - Gap ];

               A[ j ] = Tmp;
           }
   }
