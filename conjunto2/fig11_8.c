/* ECP: FILEname=fig11_8.c */
   /* If Witness Does Not return 1, N Is Definitely Composite */
   /* Do This By Computing A^i ( Mod N ) And Look For */
   /* Non-Trivial Square Roots Of 1 Along The Way */

   HugeInt
   Witness( const HugeInt A, const HugeInt i, const HugeInt N )
   {
       HugeInt X, Y;

       if( i == 0 )
           return 1;

       X = Witness( A, i / 2, N );
       if( X == 0 )  /* If N Is Recursively Composite, Stop */
           return 0;

       /* N Is Not Prime if We Find A Non-Trivial Root Of 1 */
       Y = ( X * X ) % N;
       if( Y == 1 && X != 1 && X != N - 1 )
           return 0;

       if( i % 2 )
           Y = ( A * Y ) % N;

       return Y;
   }


   /* Make NumTrials Call To Witness To Check if N Is Prime */

   int
   IsPrime( const HugeInt N )
   {
       const int NumTrials = 5;
       int Counter;

       for( Counter = 0; Counter < NumTrials; Counter++ )
           if( Witness( RandInt( 2, N - 2 ), N - 1, N ) != 1 )
               return 0;

       return 1;
   }
