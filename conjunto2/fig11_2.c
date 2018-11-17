/* ECP: FILEname=fig11_2.c */
   /* Print N As A Decimal Number */

   void
   PrintDecimal( unsigned int N )
   {
       if( N >= 10 )
           PrintDecimal( N / 10 );
       putchar( '0' + N % 10 );
   }
