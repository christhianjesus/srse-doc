/* ECP: FILEname=fig5_5.c */
   #define PrintDebug( Expr, Type ) \
       printf( "(" #Expr "): %" Type##Conv "\n", ( Expr ) )
   #define intConv         "d"
   #define doubleConv      "f"

   main( void )
   {
       int X = 5, Y = 7;
       double A = 5.0, B = 7.0;

       PrintDebug( X + Y, int  );
       PrintDebug( A + B, double  );
       return 0;
   }
