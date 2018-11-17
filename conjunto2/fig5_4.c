/* ECP: FILEname=fig5_4.c */
   #define PrintIntDebug( Expr ) \
       printf( "(" #Expr "): %d\n", ( Expr ) )

   int
   main( void )
   {
       int X = 5, Y = 7;

       PrintIntDebug( X + Y );

       return 0;
   }
