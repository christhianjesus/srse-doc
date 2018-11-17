/* ECP: FILEname=fig11_7.c */
   /* Compute X^N ( Mod P ) */

   HugeInt
   Power( const HugeInt X, const HugeInt N, const HugeInt P )
   {
       HugeInt Tmp;

       if( N == 0 )
           return 1;

       Tmp = Power( ( X * X ) % P, N / 2, P );
       
       if( N % 2 )
           Tmp = ( Tmp * X ) % P;

       return Tmp;
   }
