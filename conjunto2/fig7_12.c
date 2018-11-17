/* ECP: FILEname=fig7_12.c */
   /* Insertion Sort: Array A With N Items */

   typedef int ElementType;

   void
   InsertSort( ElementType A[ ], unsigned int N )
   {
       ElementType Tmp;
       int i, j;

       for( i = 1; i < N; i++ )
       {
           Tmp = A[ i ];
           for( j = i; j > 0 && Tmp < A[ j - 1 ]; j-- )
               A[ j ] = A[ j - 1 ];
           A[ j ] = Tmp;
       }
   }
