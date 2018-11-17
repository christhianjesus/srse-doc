/* ECP: FILEname=fig2_5.c */
   #include <stdio.h>

   main( void )
   {
       double A = 373737.0;
       double B;

       B = A*A*A + 0.37/A - A*A*A - 0.37/A;
       printf( "The value of B is %f.\n", B );
   }
