/* ECP: FILEname=fig10_13.c */
   SortedInts
   MergeM( const SortedInts A[ ], int M )
   {
       Queue Q = QuMakeEmpty( NULL );
       SortedInts One, Two, Merged;
       int i;

       for( i = 0; i < M; i++ )
           Enqueue( A[ i ], Q );

       for( i = 0; i < M-1; i++ )
       {
           Dequeue( &One, Q );
           Dequeue( &Two, Q );
           Enqueue( MergeTwo( One, Two ), Q );
       }
       Dequeue( &Merged, Q );

       QuRecycle( Q );
       return Merged;
   }
