/* ECP: FILEname=fig8_34.c */
   /* Shellsort An Array Of Strings */
   /* Do Not Move Strings, But Just Pointers */

   void
   Shellsort( const char *A[ ], const unsigned int N )
   {
       unsigned int Gap;
       const char *Tmp;
       unsigned int i, j;		/* Loop Counters */

       for( Gap = N/2; Gap > 0; Gap = Gap == 2 ? 1 : Gap / 2.2 )
           for( i = Gap; i < N; i++ )
           {
               Tmp = A[ i ];
               for( j = i; j >= Gap &&
                       strcmp( Tmp,  A[ j - Gap ] ) < 0; j -= Gap )
                   A[ j ] = A[ j - Gap ];

               A[ j ] = Tmp;
           }
   }
