/* ECP: FILEname=fig11_1.c */
   /* Compute Sum Of The First N Integers Recursively */

   unsigned long int
   Sum( unsigned int N )
   {
       if( N == 1 )                /* Base Case */
           return 1;
       else                        /* Recursive Call */
           return Sum( N - 1 ) + N;
   }
