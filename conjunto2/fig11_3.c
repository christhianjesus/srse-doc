/* ECP: FILEname=fig11_3.c */
   /* Print N In Any Base */
   /* Assumes 2 <= Base <= 16 */

   void
   PrintInt( unsigned int N, unsigned int Base )
   {
       static char DigitTable[ ] = "0123456789abcdef";

       if( N >= Base )
           PrintInt( N / Base, Base  );
       putchar( DigitTable[ N % Base ] );
   }
