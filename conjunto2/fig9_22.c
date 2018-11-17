/* ECP: FILEname=fig9_22.c */
   #include <stdio.h>
   #include "complex.h"

   main( void )
   {
       Complex A, B;

       A = InitComplex( 2.0, 4.0 );
       B = InitComplex( 0.0, 0.0 );

       AddComplex( A, A, B );
       printf( "B is: " ); PrintComplex( B ); printf( "\n" );

       return 0;
   }
