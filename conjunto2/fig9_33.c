/* ECP: FILEname=fig9_33.c */
   static const long int A = 48271;
   static const long int M = 2147483647;   /* 2^31 - 1  */
   static const long int Q = 44488;        /* M / A     */
   static const long int R = 3399;         /* M % A     */

   unsigned long int Seed = 1;

   unsigned long int
   BetterRand( void )
   {
       long int TmpSeed;

       TmpSeed = A * ( Seed % Q ) - R * ( Seed / Q );
       if( TmpSeed >= 0 )
           Seed = TmpSeed;
       else
           Seed = TmpSeed + M;

       return Seed;
   }
