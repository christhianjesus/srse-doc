/* ECP: FILEname=fig11_21.c */
   static void
   QuickSort1( ElementType A[ ], int Low, int High )
   {
       int PivotPos;

       if( Low < High )
       {
           PivotPos = Partition( A, Low, High );
           QuickSort1( A, Low, PivotPos - 1 );
           QuickSort1( A, PivotPos + 1, High );
       }
   }

   void
   QuickSort( ElementType A[ ], const unsigned int N )
   {
       QuickSort1( A, ( int ) 0, ( int ) N - 1 );
   }
