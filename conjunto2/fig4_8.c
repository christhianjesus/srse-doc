/* ECP: FILEname=fig4_8.c */
   #include "prime.h"

   /* Return True Iff N Is Prime */
   int
   IsPrime( unsigned long int N )
   {
       unsigned long int Divisor;

       if( N % 2 )
           for( Divisor = 3; N % Divisor; Divisor += 2 )
               if( Divisor * Divisor > N )
                   return 1;

       return N == 2 || N == 3;
   }


   /* Return Smallest Prime >= N */

   unsigned long int
   FindPrime( unsigned long int N )
   {
       unsigned long int TestPrime;

       TestPrime = N % 2 ? N : N + 1;
       for( ; ! IsPrime( TestPrime ); TestPrime += 2 )
           ;

       return TestPrime;
   }
