/* ECP: FILEname=fig11_4.c */
   /* Print N In Any Base */

   static char DigitTable[ ] = "0123456789abcdef";
   static const MaxBase = sizeof( DigitTable ) - 1;

   static void
   PrintInt1( unsigned int N, unsigned int Base )
   {
       if( N >= Base )
           PrintInt1( N / Base, Base  );
       putchar( DigitTable[ N % Base ] );
   }

   void
   PrintInt( unsigned int N, unsigned int Base )
   {
       if( Base <= 1 || Base > MaxBase )
           printf( "Can not print in base %u\n", Base );
       else
           PrintInt1( N, Base );
   }
