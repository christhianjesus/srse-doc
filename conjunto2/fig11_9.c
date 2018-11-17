/* ECP: FILEname=fig11_9.c */
   HugeInt
   Gcd( const HugeInt A, const HugeInt B )
   {
       if( B == 0 )
           return A;
       else
           return Gcd( B, A % B );
   }
