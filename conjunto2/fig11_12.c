/* ECP: FILEname=fig11_12.c */
   /* Return Position Of X in A */

   int
   BinarySearch1( const char *A[ ], const char *X,
                                                int Low, int High )
   {
       int Mid = ( Low + High ) / 2 ;
       int Cmp;

       if( Low > High )                          /* Not Found */
           return -1;
       if( ( Cmp = strcmp( X, A[ Mid ] ) ) < 0 ) /* X < A[ Mid ] */
           return BinarySearch1( A, X, Low, Mid - 1 );
       if( Cmp > 0 )                             /* X > A[ Mid ] */
           return BinarySearch1( A, X, Mid + 1, High );
       return Mid;                               /* X = A[ Mid ] */
   }

   int
   BinarySearch( const char *A[ ], const char *X, int N )
   {
       return BinarySearch1( A, X, 0, N - 1 );
   }
