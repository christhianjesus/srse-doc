/* ECP: FILEname=fig4_18.c */
   void
   PrintBinary( unsigned int N )
   {
       if( N >= 2 )
           PrintBinary( N >> 1 );    /* All The Other Bits */
       printf( "%d", N & 01 );    /* Least Significant Bit */
   }
