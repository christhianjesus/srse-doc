/* ECP: FILEname=fig5_8.c */
   #define Square( X ) ( ( X ) * ( X ) )

   double
   ( Square )( double X )    /* Parentheses Are Required */
   {
       return X * X;
   }

   main( void )
   {
       double A = 5.0;

       printf( "%f\n", Square( A ) );      /* Macro Call */
       printf( "%f\n", ( Square )( A++ ) );  /* Function Call */
       return 0;
   }
