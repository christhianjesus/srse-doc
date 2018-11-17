/* ECP: FILEname=fig12_6.c */
   #include <stdio.h>

   main( void )
   {
       double X;

       scanf( "%f", &X );              /* 3 */
       printf( "%f\n", X );            /* 32.000000 */
       printf( "%lf\n", X );           /* Undefined */
       scanf( "%lf", &X );             /* 3 */
       printf( "%f\n", X );            /* 3.000000 */
       printf( "%lf\n", X );           /* Undefined */

       return 0;
   }
