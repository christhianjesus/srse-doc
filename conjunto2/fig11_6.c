/* ECP: FILEname=fig11_6.c */
   /* Compute The N th Fibonacci Number */
   /* Bad Algorithm */

   unsigned long int
   Fib( unsigned int N )
   {
       if( N <= 1 )
           return N;
       else
           return Fib( N - 1 ) + Fib( N - 2 );
   }
