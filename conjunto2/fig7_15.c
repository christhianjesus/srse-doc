/* ECP: FILEname=fig7_15.c */
   void
   Shellsort( ElementType A[ ], const unsigned int N )
   {
       unsigned int Gap;
       ElementType Tmp;
       unsigned int i, j;		/* Loop Counters */

       for( Gap = N/2; Gap > 0; Gap /= 2 )
           for( i = Gap; i < N; i++ )
           {
               Tmp = A[ i ];
               for( j = i; j >= Gap && Tmp < A[ j - Gap ]; j -= Gap )
                       A[ j ] = A[ j - Gap ];

               A[ j ] = Tmp;
           }
   }
