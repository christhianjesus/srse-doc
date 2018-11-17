/* ECP: FILEname=fig4_15.c */
   static double Radicand;

   static
   double
   CubeRootEqn( double X )
   {
       return X * X * X - Radicand;
   }

   double
   Cbrt( double N )
   {
       Radicand = N;
       if( N > 0 )
           if( N > 1.0 )
               return Solve( CubeRootEqn, 1, N );
           else
               return Solve( CubeRootEqn, N, 1 );
       else
           if( N > -1.0 )
               return Solve( CubeRootEqn, -1, N );
           else
               return Solve( CubeRootEqn, N, -1 );
   }


