/* ECP: FILEname=fig11_23.c */
   #define SwapElements( i, j ) \
       {  ElementType Tmp = A[ i ]; A[ i ] = A[ j ]; A[ j ] = Tmp; }

   static int
   Partition( ElementType A[ ], int Low, int High )
   {
       int Center = ( Low + High ) / 2;
       const ElementType Pivot = A[ Center ];
       int i = Low - 1, j = High;

       SwapElements( Center, High );
       for( ; ; )
       {
           while( A[ ++i ] < Pivot )   /* Find A "large" Element */
               ;                       /* i < High Is Guaranteed */ 
           while( A[ --j ] > Pivot )   /* Find A "small" Element */
               if( j == 0 )            /* Don't run off the end! */
                   break;

           if( i >= j )
               break;

           /* Invariant: i < j, A[ i ] >= Pivot, A[ j ] <= Pivot */
           SwapElements( i, j );
       }
       SwapElements( i, High );

       return i;
   }
